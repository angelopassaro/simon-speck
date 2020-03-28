#ifndef _UTILS_H
#define _UTILS_H

#include "common.h"
#include <stdint.h>

/**
* Convert  give words in bytes
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes

*  @param words  the input word
*  @param bytes  the output bytes
*  @param numwords  the lenght of word
*/

void Words32ToBytes(u32 words[], u8 bytes[], int numwords);

/**
* Convert  give the bytes in words
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes

*  @param bytes  the input bytes
*  @param word  the output word
*  @param numbytes  the lenght of bytes
*/
void BytesToWords32(u8 bytes[], u32 words[], int numbytes);

/**
* Convert  give words in bytes
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes
*  @param bytes  the input bytes
*  @param word  the output word
*  @param numbytes  the lenght of bytes
*/

void Words64ToBytes(u64 words[], u8 bytes[], int numwords);

/**
* Convert  give the bytes in words
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes
*
*  @param bytes  the input bytes
*  @param words  the output words
*  @param numbytes  the lenght of bytes
*/
void BytesToWords64(u8 bytes[], u64 words[], int numbytes);

#endif
