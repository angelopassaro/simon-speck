#include "cbc.h"
#include "../common/utils.h"

#include <string.h>

#define DEBUG
#ifdef DEBUG
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
#endif

// change return type for error check
void cbcEncrypt64(cypher64 cypher, u8 *iv, u8 *plaintext, u8 *ciphertext, u8 length, u32 *rk)
{

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("=====================================\n");
#endif

    //check if the length of plaintext is suitable for encrypt
    if (length % cypher.blockSize != 0)
    {
#ifdef DEBUG
        printf("Error");
        printf("=====================================\n");
        return;
#endif
    }

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("=====================================\n");
#endif
    /**
    * For every block:
    * 1. xor between iv and n bytes of plaintext
    * 2. split xored bytes 
    * 3. encrypt
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {

        /**
         * STEP 1
         */
        u8 xored[cypher.blockSize];
        for (int c = 0; c < cypher.blockSize; c++)
        {
            xored[c] = plaintext[(c) + (cypher.blockSize * i)] ^ iv[c];
        }

#ifdef DEBUG
        printf("xored \n");
        hex_print((u8 *)xored, 0, cypher.blockSize);
        printf("=====================================\n");
#endif

        /**
         * STEP 2
         */
        u32 Pt[2];
        BytesToWords32((u8 *)xored, Pt, cypher.blockSize);

        /**
         * STEP 3
         */
        u32 Ct[2];
        cypher.encrypt(Pt, Ct, rk);

        /**
         * STEP 4
         */
        u8 ct[16];
        Words32ToBytes(Ct, ct, 2);
        memcpy(&iv[i * cypher.blockSize], ct, cypher.blockSize);

        /**
         *  STEP 5
         */
        memcpy(&ciphertext[i * cypher.blockSize], ct, cypher.blockSize);
    }
}

void cbcDecrypt64(cypher64 cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u32 *rk)
{
#ifdef DEBUG
    printf("======START DEBUG DECRYPT:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("==================================\n");
#endif

    //check if the length of plaintext is suitable for encrypt
    if (length % cypher.blockSize != 0)
    {
#ifdef DEBUG
        printf("Error");
        printf("==================================\n");
        return;
#endif
    }

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("==================================\n");
#endif
    /**
    * For every block:
    * 1. split ciphertext word
    * 2. decrypt
    * 3. xor between cypher and iv
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {

#ifdef DEBUG
        printf("cypher \n");
        hex_print(&ciphertext[i * cypher.blockSize], 0, cypher.blockSize);
        printf("==================================\n");
#endif

        /**
         * STEP 1
         */
        u32 Ct[2];
        BytesToWords32(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);

        /**
         * STEP 2
         */
        u32 Pt[2];
        u8 pt[16];
        cypher.decrypt(Pt, Ct, rk);
        Words32ToBytes(Pt, pt, 2);

        /**
         * STEP 4
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            iv[c] ^= pt[c];
        }

#ifdef DEBUG
        printf("xored \n");
        hex_print((u8 *)iv, 0, cypher.blockSize);
        printf("==================================\n");
#endif

        memcpy(&plaintext[i * cypher.blockSize], iv, cypher.blockSize);

        /**
         * STEP 5
         */
        memcpy(&iv[i * cypher.blockSize], Ct, cypher.blockSize);
    }
}

void cbcEncrypt128(cypher128 cypher, u8 *iv, u8 *plaintext, u8 *ciphertext, u8 length, u64 *rk)
{

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("=====================================\n");
#endif

    //check if the length of plaintext is suitable for encrypt
    if (length % cypher.blockSize != 0)
    {
#ifdef DEBUG
        printf("Error");
        printf("=====================================\n");
        return;
#endif
    }

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("=====================================\n");
#endif
    /**
    * For every block:
    * 1. xor between iv and n bytes of plaintext
    * 2. split xored bytes 
    * 3. encrypt
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {

        /**
         * STEP 1
         */
        u8 xored[cypher.blockSize];
        for (int c = 0; c < cypher.blockSize; c++)
        {
            xored[c] = plaintext[(c) + (cypher.blockSize * i)] ^ iv[c];
        }

#ifdef DEBUG
        printf("xored \n");
        hex_print((u8 *)xored, 0, cypher.blockSize);
        printf("=====================================\n");
#endif

        /**
         * STEP 2
         */
        u64 Pt[2];
        BytesToWords64((u8 *)xored, Pt, cypher.blockSize);

        /**
         * STEP 3
         */
        u64 Ct[2];
        cypher.encrypt(Pt, Ct, rk);

        /**
         * STEP 4
         */
        u8 ct[16];
        Words64ToBytes(Ct, ct, 2);
        memcpy(&iv[i * cypher.blockSize], ct, cypher.blockSize);

        /**
         *  STEP 5
         */
        memcpy(&ciphertext[i * cypher.blockSize], ct, cypher.blockSize);
    }
}

void cbcDecrypt128(cypher128 cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u64 *rk)
{
#ifdef DEBUG
    printf("======START DEBUG DECRYPT:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("==================================\n");
#endif

    //check if the length of plaintext is suitable for encrypt
    if (length % cypher.blockSize != 0)
    {
#ifdef DEBUG
        printf("Error");
        printf("==================================\n");
        return;
#endif
    }

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("==================================\n");
#endif
    /**
    * For every block:
    * 1. split ciphertext word
    * 2. decrypt
    * 3. xor between cypher and iv
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {

#ifdef DEBUG
        printf("cypher \n");
        hex_print(&ciphertext[i * cypher.blockSize], 0, cypher.blockSize);
        printf("==================================\n");
#endif

        /**
         * STEP 1
         */
        u64 Ct[2];
        BytesToWords64(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);

        /**
         * STEP 2
         */
        u64 Pt[2];
        u8 pt[16];
        cypher.decrypt(Pt, Ct, rk);
        Words64ToBytes(Pt, pt, 2);

        printf("iv: ");
        hex_print(iv, 0, 16);
        /**
         * STEP 4
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            iv[c] ^= pt[c];
        }

#ifdef DEBUG
        printf("xored \n");
        hex_print((u8 *)iv, 0, cypher.blockSize);
        printf("==================================\n");
#endif

        memcpy(&plaintext[i * cypher.blockSize], iv, cypher.blockSize);

        /**
         * STEP 5
         */
        memcpy(&iv[i * cypher.blockSize], Ct, cypher.blockSize);
    }
}
