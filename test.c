//#define SPECK6496
//#define SPECK64128
#define SPECK128128
//#define SPECK128192
//#define SPECK128256
//#define SIMON6496
//#define SIMON64128
//#define SIMON128128
//#define SIMON128192
//#define SIMON128256

#ifdef SPECK6496
#include "speck/speck6496.c"
#define SPECK
#define KEY_LEN 3
#define KEY_ROUND 26
#define S64
#endif

#ifdef SPECK64128
#include "speck/speck64128.c"
#define SPECK
#define KEY_LEN 4
#define KEY_ROUND 27
#define S64
#endif

#ifdef SPECK128128
#include "speck/speck128128.c"
#define SPECK
#define KEY_LEN 2
#define KEY_ROUND 32
#define S128
#endif

#ifdef SPECK128192
#include "speck/speck128192.c"
#define SPECK
#define KEY_LEN 3
#define KEY_ROUND 33
#define S128
#endif

#ifdef SPECK128256
#include "speck/speck128256.c"
#define SPECK
#define KEY_LEN 4
#define KEY_ROUND 34
#define S128
#endif

#ifdef SIMON6496
#include "simon/simon6496.c"
#define SIMON
#define KEY_LEN 3
#define KEY_ROUND 42
#define S64
#endif

#ifdef SIMON64128
#include "simon/simon64128.c"
#define SIMON
#define KEY_LEN 4
#define KEY_ROUND 44
#define S64
#endif

#ifdef SIMON128128
#include "simon/simon128128.c"
#define SIMON
#define KEY_LEN 2
#define KEY_ROUND 68
#define S128
#endif

#ifdef SIMON128192
#include "simon/simon128192.c"
#define SIMON
#define KEY_LEN 3
#define KEY_ROUND 69
#define S128
#endif

#ifdef SIMON128256
#include "simon/simon128256.c"
#define SIMON
#define KEY_LEN 4
#define KEY_ROUND 72
#define S128
#endif

#include <stdio.h>

static void
hex_print(uint8_t *pv, uint16_t s, uint16_t len)
{
    uint8_t *p = pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        unsigned int i;
        for (i = s; i < len; ++i)
            printf("%02x ", p[i]);
    }
    printf("\n\n");
}

int main()
{

/************************************************************************************************************************************************************
 *                                                                  Simon
 * *********************************************************************************************************************************************************/
#ifdef SPECK
#ifdef SPECK6496
    //test vector
    u8 pt[8] = {
        0x65, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74};
    u8 k[12] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13};
    u8 ct[8];
    u32 K[KEY_LEN]; //3 * 32
    u32 Pt[2];
    u32 Ct[2];
    u32 rk[KEY_ROUND];
#endif

#ifdef SPECK64128
    //test vector
    u8 pt[8] = {
        0x2d, 0x43, 0x75, 0x74, 0x74, 0x65, 0x72, 0x3b};
    u8 k[16] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13, 0x18, 0x19, 0x1a, 0x1b};
    u8 ct[8];
    u32 K[KEY_LEN]; //4 * 32
    u32 Pt[2];
    u32 Ct[2];
    u32 rk[KEY_ROUND];
#endif

#ifdef SPECK128128
    //test vector
    u8 pt[16] = {
        0x20, 0x6d, 0x61, 0x64, 0x65, 0x20, 0x69, 0x74, 0x20, 0x65, 0x71, 0x75, 0x69, 0x76, 0x61, 0x6c};
    u8 k[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    u8 ct[16];
    u64 K[KEY_LEN]; //2 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef SPECK128192
    //test vector
    u8 pt[16] = {
        0x65, 0x6e, 0x74, 0x20, 0x74, 0x6f, 0x20, 0x43, 0x68, 0x69, 0x65, 0x66, 0x20, 0x48, 0x61, 0x72};
    u8 k[24] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
    u8 ct[16];
    u64 K[KEY_LEN]; //3 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef SPECK128256
    //test vector
    u8 pt[16] = {
        0x70, 0x6f, 0x6f, 0x6e, 0x65, 0x72, 0x2e, 0x20, 0x49, 0x6e, 0x20, 0x74, 0x68, 0x6f, 0x73, 0x65};
    u8 k[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

    u8 ct[16];
    u64 K[4]; // 4 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef S64
    BytesToWords32((u8 *)pt, (u32 *)Pt, sizeof(pt));
    for (int i = 0; i < 2; i++)
        printf("Pt[%d]: %2lx\n", i, Pt[i]);
    printf("\n");

    BytesToWords32(k, K, sizeof(k));
    for (int i = 0; i < KEY_LEN; i++)
        printf("k[%d]: %2lx\n", i, K[i]);
    printf("\n");
#else
    BytesToWords64((u8 *)pt, (u64 *)Pt, sizeof(pt));
    for (int i = 0; i < 2; i++)
        printf("Pt[%d]: %2lx\n", i, Pt[i]);
    printf("\n");

    BytesToWords64(k, K, sizeof(k));
    for (int i = 0; i < KEY_LEN; i++)
        printf("k[%d]: %2lx\n", i, K[i]);
    printf("\n");
#endif

    SpeckKeySchedule(K, rk);
    for (int i = 0; i < KEY_ROUND; i++)
        printf("rk[%d]: %2lx\n", i, rk[i]);
    printf("\n");

    SpeckEncrypt(Pt, Ct, rk);
    for (int i = 0; i < 2; i++)
        printf("Ct[%d]: %2lx\n", i, Ct[i]);
    printf("\n");

#ifdef S64
    Words32ToBytes(Ct, ct, 2);
    hex_print((u8 *)ct, 0, 8);

    //decrypt
    BytesToWords32((u8 *)ct, Ct, sizeof(ct));
    SpeckDecrypt(Pt, Ct, rk);
    hex_print((u8 *)Pt, 0, 8);
#else
    Words64ToBytes(Ct, ct, 2);
    hex_print((u8 *)ct, 0, 16);

    //decrypt
    BytesToWords64((u8 *)ct, Ct, 8);
    SpeckDecrypt(Pt, Ct, rk);
    hex_print((u8 *)Pt, 0, 16);
#endif
#endif
/************************************************************************************************************************************************************
 *                                                                  Simon
 * *********************************************************************************************************************************************************/
#ifdef SIMON
#ifdef SIMON6496
    //test vector
    u8 pt[8] = {
        0x63, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x72, 0x6f};
    u8 k[12] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13};

    u8 ct[8];
    u32 K[KEY_LEN]; //3 * 32
    u32 Pt[2];
    u32 Ct[2];
    u32 rk[KEY_ROUND];
#endif
#ifdef SIMON64128
    //test vector
    u8 pt[8] = {
        0x75, 0x6e, 0x64, 0x20, 0x6c, 0x69, 0x6b, 0x65};
    u8 k[16] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13, 0x18, 0x19, 0x1a, 0x1b};
    u8 ct[8];
    u32 K[KEY_LEN]; //4 * 32
    u32 Pt[2];
    u32 Ct[2];
    u32 rk[KEY_ROUND];
#endif

#ifdef SIMON128128
    //test vector
    u8 pt[16] = {
        0x20, 0x74, 0x72, 0x61, 0x76, 0x65, 0x6c, 0x6c, 0x65, 0x72, 0x73, 0x20, 0x64, 0x65, 0x73, 0x63};
    u8 k[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    u8 ct[16];
    u64 K[KEY_LEN]; //2 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef SIMON128192
    //test vector
    u8 pt[16] = {
        0x72, 0x69, 0x62, 0x65, 0x20, 0x77, 0x68, 0x65, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x72, 0x65, 0x20};
    u8 k[24] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
    u8 ct[16];
    u64 K[KEY_LEN]; //3 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef SIMON128256
    //test vector
    u8 pt[16] = {
        0x69, 0x73, 0x20, 0x61, 0x20, 0x73, 0x69, 0x6d, 0x6f, 0x6f, 0x6d, 0x20, 0x69, 0x6e, 0x20, 0x74};
    u8 k[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
    u8 ct[16];
    u64 K[KEY_LEN]; //4 * 64
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[KEY_ROUND];
#endif

#ifdef S64
    BytesToWords32((u8 *)pt, (u32 *)Pt, sizeof(pt));
    for (int i = 0; i < 2; i++)
        printf("Pt[%d]: %2lx\n", i, Pt[i]);
    printf("\n");

    BytesToWords32(k, K, sizeof(k));
    for (int i = 0; i < KEY_LEN; i++)
        printf("k[%d]: %2lx\n", i, K[i]);
    printf("\n");
#else
    BytesToWords64((u8 *)pt, (u64 *)Pt, sizeof(pt));
    for (int i = 0; i < 2; i++)
        printf("Pt[%d]: %2lx\n", i, Pt[i]);
    printf("\n");

    BytesToWords64(k, K, sizeof(k));
    for (int i = 0; i < KEY_LEN; i++)
        printf("k[%d]: %2lx\n", i, K[i]);
    printf("\n");
#endif

    SimonKeySchedule(K, rk);
    for (int i = 0; i < KEY_ROUND; i++)
        printf("rk[%d]: %2lx\n", i, rk[i]);
    printf("\n");

    SimonEncrypt(Pt, Ct, rk);
    for (int i = 0; i < 2; i++)
        printf("Ct[%d]: %2lx\n", i, Ct[i]);
    printf("\n");

#ifdef S64
    Words32ToBytes(Ct, ct, 2);
    hex_print((u8 *)ct, 0, 8);

    //decrypt
    BytesToWords32((u8 *)ct, Ct, sizeof(ct));
    SimonDecrypt(Pt, Ct, rk);
    hex_print((u8 *)Pt, 0, 8);
#else
    Words64ToBytes(Ct, ct, 2);
    hex_print((u8 *)ct, 0, 16);

    //decrypt
    BytesToWords64((u8 *)ct, Ct, sizeof(ct));
    SimonDecrypt(Pt, Ct, rk);
    hex_print((u8 *)Pt, 0, 16);
#endif
#endif
}
