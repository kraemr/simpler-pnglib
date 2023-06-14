# simpler-pnglib
is a rewrite of my simple-pnglib in c which will be faster and simpler to use

# How to use

First clone the repo with submodule
`git clone --recurse-submodules https://github.com/kraemr/simpler-pnglib`


Then cd into it
`cd simpler-pnglib`

compile zlib-ng with cmake and make
then use the compiled zlib-ng with your cmake or g++
<code>
g++ yourfile.cpp simpler-pnglib/*.c libz-ng.a
gcc yourfile.c simpler-pnglib/*.c libz-ng.a
</code>
# Code Example

<code>
    unsigned char  * pixel_buffer;
    struct SPNG_INFO spnginf;
    int inf =  SPNG_read("Testimage.png",&spnginf); // reads and allocates internal buffers
    // copies values to your buffer allocates it and writes the new properties into spnginf
    SPNG_get_pixels_srgb(&spnginf,&pixel_buffer,0); 
    FILE * fp = fopen("out.png","wb");
    SPNG_write_metadata(fp, &spnginf);
    SPNG_write(fp, &spnginf, pixel_buffer); // THIS writes the given pixel data
    SPNG_exit(); // closes all internal buffers AND THE FILEPOINTER
    free(ff);
</code>
