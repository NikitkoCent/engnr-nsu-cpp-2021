#include <iostream>
#include "hash_funcs.h"

uint64_t block_to_uint64(const char block[], int64_t length){
    uint64_t total = 0;
    for(int i = 0; i < length; i++){
        total <<= 8;
        total |= static_cast<unsigned char>(block[i]);
    }
    return total;
}

uint64_t sum64(std::ifstream &file){
    char block[8] {};
    uint64_t hash = 0;
    while(file.get(block, 8))
    {
        hash += block_to_uint64(block, file.gcount());
    }
    return hash;
}

uint32_t adler32(std::ifstream &file){
    const uint32_t MOD_ADLER = 65521;
    uint32_t a = 1, b = 0;
    unsigned char c;
    while(file >> c)
    {
        a = (a + c) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    return (b << 16) | a;
}