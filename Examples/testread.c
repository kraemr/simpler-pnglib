#include "../include/spnglib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    unsigned char  * ff;
    struct SPNG_INFO spnginf;
    int inf =  SPNG_read("Testimage.png",&spnginf);
    SPNG_get_pixels_srgb(&spnginf,&ff,0);
    struct SPNG_AUTHORINFO spngauthinf;
    SPNG_get_Authorinfo(&spngauthinf);   
    FILE * fp = fopen("out.png","wb");
    SPNG_write_metadata(fp, &spnginf);
    SPNG_write_authorinfo(fp,spngauthinf);
    SPNG_write(fp,&spnginf,ff);
    SPNG_free_author_info(&spngauthinf);
    SPNG_exit();
    free(ff);
} 
