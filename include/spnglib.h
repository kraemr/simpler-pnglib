
#define SPNG_ERROR -1
#define SPNG_FILE_NOT_FOUND -2
#define SPNG_NOT_ALLOCATED -3
#define SPNG_SUCCESS 0
#define SPNG_WRITTEN_AS_INDEXED 10

struct SPNG_PIXEL{
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char a;
};
struct SPNG_INFO {
unsigned int width; 
unsigned int height;
unsigned char bitdepth;
unsigned char clr; //Colortype ie RGB,RGBA,greyscale..
unsigned long size; //size of the pixelbuffer
unsigned char bytespp;// if greyscale 1 rgb 3 greyalpha 2 rgba 4
};

extern unsigned char * g_spng_IDAT_BUFFER_unfiltered;
//reads the give image and writes dimensions, 
//color and more to spnginf which is passed as a reference
int SPNG_read(char * filename,struct SPNG_INFO* spnginf);
void SPNG_get_pixels(unsigned char** pixelbuffer);//gets the pixel values without converting
void SPNG_get_pixels_greyscale(struct SPNG_INFO* spnginf,unsigned char** pixelbuffer,unsigned char withAlpha);
// spnginf holds the dimensions,clrtype and other things
int SPNG_write(char * filename,struct SPNG_INFO* spnginf,unsigned char* in_pix_buf);
int SPNG_write_indexed(char * filename,struct SPNG_INFO* spnginf,unsigned char* in_pix_buf);

void SPNG_exit();// deallocates internal Buffer call this when you are finished to avoid memleaks
void SPNG_get_pixels_srgb(struct SPNG_INFO* spnginf,unsigned char** pixelbuffer,unsigned char withAlpha);
int SPNG_get_spnginfo(struct SPNG_INFO* spnginf);
int SPNG_get_spnginfo_from_file(char * filename,struct SPNG_INFO* spnginf);
