#include "include/spnglib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    unsigned char  * ff;
    struct SPNG_INFO spnginf;
//    float startTime = (float)clock()/CLOCKS_PER_SEC;
//    float endTime = (float)clock()/CLOCKS_PER_SEC;
//    float timeElapsed = endTime - startTime;
//    printf("%f",timeElapsed);
/* Do work */



    int inf =  SPNG_read("Testimage.png",&spnginf);

  
    SPNG_get_pixels(&ff);
    SPNG_exit();
    //printf("%d",inf);
    //SPNG_write("out.png", &spnginf, ff);
    
    
    free(ff);

    
} 
