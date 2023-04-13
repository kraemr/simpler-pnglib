#include "include/spnglib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int spng_deflate_txt(FILE * fp,char * data,int data_len){
    if(fp == NULL) return SPNG_NULL;
    const size_t CHUNK_SIZE = 16384;
    unsigned char dest_buf[CHUNK_SIZE];
    int ret;
    zng_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data_len;
    strm.next_in = (Bytef*)data;
    strm.avail_out = CHUNK_SIZE;
    strm.next_out = (Bytef*)dest_buf;

    ret = zng_deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK) {
        return ret;
    }

    do {
        ret = zng_deflate(&strm, Z_FINISH);
        if (ret == Z_STREAM_ERROR) {
            zng_deflateEnd(&strm);
            return ret;
        }

        size_t have = CHUNK_SIZE - strm.avail_out;
        if (fwrite(dest_buf, 1, have, fp) != have) {
            zng_deflateEnd(&strm);
            return Z_ERRNO;
        }

        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)dest_buf;
    } while (ret != Z_STREAM_END);
    g_spng_crc = zng_crc32(g_spng_crc, dest_buf, strm.total_out);
    g_spng_crc = __builtin_bswap32(g_spng_crc);
    fwrite(&g_spng_crc,1,4,fp);
    zng_deflateEnd(&strm);
    return Z_OK;
}


// Writes a given keyword and its data after also writing the chunk id
int spng_write_keyword_data(FILE * fp,const unsigned char* ID,char * keyword,int keyword_len,char * data,int data_len,unsigned char should_be_compressed){
    if(fp == NULL) return SPNG_NULL;
    fwrite(ID,1,4,fp);
    fwrite(keyword,1,keyword_len,fp );
    fputc('\0',fp);
    g_spng_crc = zng_crc32(0L, Z_NULL, 0L);
    g_spng_crc = zng_crc32(g_spng_crc, keyword, keyword_len);
    g_spng_crc = zng_crc32(g_spng_crc, '\0', 1);
    
    if(should_be_compressed){
        spng_deflate(fp,data,data_len);
    }else{
        fwrite(data,1,data_len,fp);
        g_spng_crc = zng_crc32(g_spng_crc, data, data_len);
        g_spng_crc = __builtin_bswap32(g_spng_crc);
        fwrite(&g_spng_crc,1,4,fp);
    }


    return 1;
}



int SPNG_write_authorinfo(FILE * fp,struct SPNG_AUTHORINFO spngauthinf){
    // write Title as Txt
    // Author as Txt
    // Description as ztxt
    // Comment as ztxt
    // author as txt
    // Disclaimer as ztxt
    // creation time as txt
    // Copyright as ztxt
    // Source as txt
    spng_write_keyword_data(fp,g_spng_tExT_ID,"Title",5,spngauthinf.title,spngauthinf.title_len,0);
    spng_write_keyword_data(fp,g_spng_tExT_ID,"Author",6,spngauthinf.author,spngauthinf.author_len,0);
    spng_write_keyword_data(fp,g_spng_zTXt_ID,"Description",11,spngauthinf.description,spngauthinf.description_len,1);


}