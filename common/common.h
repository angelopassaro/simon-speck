#ifndef _COMMON_H
#define _COMMON_H

#define u8 uint8_t
#define u32 uint32_t
#define u64 uint64_t

#define ROTL32(x, r) (((x) << (r)) | (x >> (32 - (r))))
#define ROTR32(x, r) (((x) >> (r)) | ((x) << (32 - (r))))
#define ROTL64(x, r) (((x) << (r)) | (x >> (64 - (r))))
#define ROTR64(x, r) (((x) >> (r)) | ((x) << (64 - (r))))

#define ER64(x, y, s) (x = (ROTR64(x, 8) + y) ^ (s), y = ROTL64(y, 3) ^ x)
#define DR64(x, y, k) (y ^= x, y = ROTR64(y, 3), x ^= k, x -= y, x = ROTL64(x, 8))

#endif
