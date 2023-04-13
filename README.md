# simpler-pnglib
is a rewrite of my simple-pnglib in c which will be faster and simpler to use

# How to use

First clone the repo with submodule
`git clone --recurse-submodules https://github.com/kraemr/simpler-pnglib/.git`


Then cd into it
`cd simpler-pnglib`

Then execute either setup_linux.sh or setup_windows.bat
The resulting static libraries will be in the build folder
Then you will need to include the .h files in include in your .c or .cpp files to use the library and of course you will need to link with them as well

# Code Example

<code>
    unsigned char  * pixel_buffer;
    struct SPNG_INFO spnginf;
    int inf =  SPNG_read("Testimage.png",&spnginf); // reads and allocates internal buffers
    // copies values to your buffer allocates it and writes the new properties into spnginf
    SPNG_get_pixels_srgb(&spnginf,&pixel_buffer,0); 
    SPNG_write("out.png", &spnginf, ff); // THIS writes the given pixel data
    SPNG_exit();
    free(ff);
</code>
