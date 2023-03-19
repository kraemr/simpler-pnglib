#include "include/spnglib.h"
#include <stdio.h>
#include <string.h>

void spng_change_endian(unsigned int * n){
*n = (*n >> 24) | ((*n >> 8) & 0x0000ff00) | ((*n<<8) & 0x00ff0000) | (*n << 24);
}

void spng_metadata_deflate_ztxt(unsigned char * ztxt_str ,char * out_str,unsigned int * out_len){

}

int SPNG_read_metadata(char * filename,struct SPNG_METADATA * spng_metadata){
    if(filename == NULL)return SPNG_NULL;
    FILE * fp = fopen(filename,"rb");
    if(fp == NULL) return SPNG_FILE_NOT_FOUND;
    unsigned char b[4];
    unsigned char spng_PLTE_ID[]={0x50,0x4c,0x54,0x45};
    unsigned char spng_TRNS_ID[]={0x74,0x52,0x4e,0x53};
    unsigned char spng_tExT_ID[]={116,69,88,116}; //tEXT
    unsigned char spng_zTXt_ID[]={122,84,88,116}; //zTXt
    unsigned char IHDR_identifier[]={0x49,0x48,0x44,0x52};
    unsigned char phys_ID[]={112,72,89,115}; //pHYs

    char * author_str = "Author";
    char * title_str = "Title";
    char buffer[6]={0,0,0,0,0,0};

    while(!feof(fp)){
        fread(b,1,4,fp);
        if(memcmp(spng_PLTE_ID,b,4) == 0 
        || memcmp(spng_TRNS_ID,b,4) == 0 
        || memcmp(IHDR_identifier, b, 4) == 0 
        || memcmp(phys_ID, b,  4) == 0 ){

            fseek(fp,-8,SEEK_CUR);
            unsigned int chnklen = 0;
            fread(&chnklen,1,4,fp);
            spng_change_endian(&chnklen);
            fseek(fp, 4, SEEK_CUR);
            fseek(fp,chnklen,SEEK_CUR);
            fseek(fp,4,SEEK_CUR);
            
        }
        else if(memcmp(spng_tExT_ID,b,4) == 0){
            fseek(fp,-8,SEEK_CUR);
            unsigned int chnklen = 0;
            fread(&chnklen,1,4,fp);
            spng_change_endian(&chnklen);
            fseek(fp, 4, SEEK_CUR);
            fread(buffer,1,6,fp);
            if(buffer[3] == 'l'){
                printf("%c%c%c%c%c%x\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
                spng_metadata->title_len = chnklen;
                spng_metadata->title = (unsigned char*)malloc(chnklen-6+1);
                fread(spng_metadata->title,1,chnklen-6,fp);
                spng_metadata->title[chnklen] = '\0';
            }else if(buffer[3] == 'h'){
                 fseek(fp,1,SEEK_CUR);
                spng_metadata->author_len = chnklen;
                spng_metadata->author = (unsigned char*)malloc(chnklen+1);
                fread(spng_metadata->author,1,chnklen-7,fp);
                spng_metadata->author[chnklen] = '\0';
            }
        }
        else if(memcmp(spng_zTXt_ID,b,4) == 1){

        }
    }
    fclose(fp);


    return SPNG_SUCCESS;
}