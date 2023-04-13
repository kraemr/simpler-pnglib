#include "../include/spnglib.h"
#include <stdio.h>

int main(int argc , char * argv[]){
    struct SPNG_INFO  s;
    SPNG_get_spnginfo_from_file(argv[1],&s );
    printf("clr:%d , w:%d , h:%d",s.clr,s.width,s.height);
}