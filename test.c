#define speck128256
#ifdef speck128256
#include "speck/speck128256.c"
#endif
#include "speck/speck.h"
#include <stdio.h>

static void hex_print(uint8_t *pv, uint16_t s, uint16_t len)
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
#ifdef speck128256
    //test vector
    u8 pt[16] = {
        0x70, 0x6f, 0x6f, 0x6e, 0x65, 0x72, 0x2e, 0x20, 0x49, 0x6e, 0x20, 0x74, 0x68, 0x6f, 0x73, 0x65};
    u8 k[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

    u8 ct[16];
    u64 K[4];
    u64 Pt[2];
    u64 Ct[2];
    u64 rk[34]; // speck 128/256 34 round

    BytesToWords64((u8 *)pt, (u64 *)Pt, 16);
    for (int i = 0; i < 2; i++)
        printf("Pt[%d]: %2lx\n", i, Pt[i]);
    printf("\n");

    BytesToWords64((u8 *)k, K, 32);
    for (int i = 0; i < 4; i++)
        printf("k[%d]: %2lx\n", i, K[i]);
    printf("\n");

    SpeckKeySchedule(K, rk);
    for (int i = 0; i < 34; i++)
        printf("rk[%d]: %2lx\n", i, rk[i]);
    printf("\n");

    SpeckEncrypt(Pt, Ct, rk);
    for (int i = 0; i < 2; i++)
        printf("Ct[%d]: %2lx\n", i, Ct[i]);
    printf("\n");

    Words64ToBytes(Ct, ct, 2);
    hex_print((u8 *)ct, 0, 16);

    //Decrypt
    BytesToWords64((u8 *)ct, Ct, 16);
    SpeckDecrypt(Pt, Ct, rk);
    hex_print((u8 *)Pt, 0, 16);
#endif
}
