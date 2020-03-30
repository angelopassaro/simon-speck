#ifndef _CBC_MODE_H
#define _CBC_MODE_H

#include "../common/common.h"

/**
* Encryption in CBC mode
* @param cypher Algorithm
* @param iv Initial vector
* @param plaintext Plaintext to be encrypted
* @param ciphertext Ciphertext resulting from the encryption
* @param length Length of data bytes to be encrypted
* @param rk Round key
 */
void cbcEncrypt64(cypher cypher, u8 *iv, u8 *plaintext, u8 ciphertext[], u8 lenght, u32 *rk);

/**
* Decryption in CBC mode
* @param cypher Algorithm
* @param iv Initial vector
* @param ciphertext Ciphertext to be decrypted
* @param plaintext Plaintext resulting from decryption
* @param length Length of data bytes to be decrypted
* @param rk Round key
 */
void cbcDecrypt64(cypher cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u32 *rk);

/**
* Encryption in CBC mode
* @param cypher Algorithm
* @param iv Initial vector
* @param plaintext Plaintext to be encrypted
* @param ciphertext Ciphertext resulting from the encryption
* @param length Length of data bytes to be encrypted
* @param rk Round key
 */
void cbcEncrypt128(cypher cypher, u8 *iv, u8 *plaintext, u8 *ciphertext, u8 length, u64 rk);

/**
* Decryption in CBC mode
* @param cypher Algorithm
* @param iv Initial vector
* @param ciphertext Ciphertext to be decrypted
* @param plaintext Plaintext resulting from decryption
* @param length Length of data bytes to be decrypted
* @param rk Round key
 */
void cbcDecrypt128(cypher cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u64 rk);

#endif