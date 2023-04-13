#include "../include/spnglib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int err_msg(char * err){
    printf("%s\n",err);
    return 1;
}


void print_help(){
    printf("Usage: ./convpng.out input_filename_here new_file_name colortype\n");
    printf("Available colortypes: -i for indexed, -rgb for rgb, -rgba for rgba \n");
    printf("-g for greyscale, -ga for greyscale alpha\n");
}

int main(int argc , char  * argv[]){
    unsigned int  clr;
    if(argc < 3){
        printf("Missing arguments\n");
        print_help();
        return 1;
    }
    if(argv[1] == NULL){
        return err_msg("No input file given");
    }
    if(argv[2] == NULL){
        return err_msg("No output filename given");
    }
    struct SPNG_INFO spnginf;
    SPNG_read(argv[1], &spnginf);
    unsigned char * pixel_buffer;

    if(argv[3] == NULL){
        SPNG_get_pixels(&pixel_buffer);
    }    
    if(strcmp(argv[3],"-i") == 0 ||strcmp( argv[3] ,"--indexed") == 0){
        printf("Writing file as indexed");
        SPNG_get_pixels(&pixel_buffer);
        SPNG_write_indexed(argv[2], &spnginf, pixel_buffer);
        SPNG_exit();
        free(pixel_buffer);
        return 0;
    }
    
    if(strcmp(argv[3] , "-g")  == 0|| strcmp(argv[3] , "--greyscale") == 0)
        SPNG_get_pixels_greyscale(&spnginf,&pixel_buffer,0);
    else if(strcmp(argv[3] , "-ga") == 0 || strcmp(argv[3] , "--greyscale_alpha") == 0)
        SPNG_get_pixels_greyscale(&spnginf,&pixel_buffer,1);
    else if(strcmp(argv[3] , "-rgba") == 0)
        SPNG_get_pixels_srgb(&spnginf,&pixel_buffer,1);
    else if(strcmp(argv[3] , "-rgb") == 0) {
        SPNG_get_pixels_srgb(&spnginf,&pixel_buffer,0);
    }
    SPNG_write(argv[2], &spnginf, pixel_buffer);
    SPNG_exit();
    free(pixel_buffer);

    
}