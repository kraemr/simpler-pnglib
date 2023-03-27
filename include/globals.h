#define SPNG_NOFILTER 0
#define SPNG_SUB 1
#define SPNG_UP 2
#define SPNG_AVG 3
#define SPNG_PAETH 4

extern const unsigned char g_spng_IDAT_ID[4];
extern const unsigned char g_spng_PLTE_ID[4];
extern const unsigned char g_spng_PNG_ID[8];
extern const unsigned char g_spng_TRNS_ID[4];
extern const unsigned char g_spng_tExT_ID[4];
extern const unsigned char g_spng_zTXt_ID[4];
extern const unsigned char g_spng_IHDR_ID[4];
extern const unsigned char g_spng_phys_ID[4];
extern const unsigned char g_spng_iTXt_ID[4];
extern const unsigned char g_spng_bkgd_ID[4];
extern const unsigned char g_spng_cHRM_ID[4];
extern const unsigned char g_spng_gAMA_ID[4];
extern const unsigned char g_spng_iCCP_ID[4];
extern const unsigned char g_spng_sRGB_ID[4];
extern const unsigned char g_spng_sBIT_ID[4];
extern const unsigned char g_spng_sPLT_ID[4];
extern const unsigned char g_spng_tIME_ID[4];
extern const unsigned char g_spng_hIST_ID[4];
extern const unsigned char g_spng_IHDR_ID[4];
extern const unsigned char g_spng_phys_ID[4];
extern  unsigned int g_spng_crc; // global crc val
extern  unsigned int g_spng_bytes_rwritten;
extern  unsigned char g_spng_is_little_endian;

#ifdef SPNGLIB_DEBUG_BENCHMARK
    #include <time.h>
    #include <stdio.h>
    extern  float SPNG_BENCH_START;
    extern  float SPNG_BENCH_END;
    extern  float SPNG_BENCH_ELAPSED;
    extern unsigned int SUB_COUNT;
    extern unsigned int UP_COUNT;
    extern unsigned int AVG_COUNT;
    extern unsigned int PAETH_COUNT;
    extern unsigned int NOFILTER_COUNT;
    void spng_bench_start();
    void spng_bench_end(char * endmsg);
#endif