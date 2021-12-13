//
// Created by Dasha Shestakova on 13.12.2021.
//

#include "HashCalc.h"

uint32_t HashCalc::Adler32(std::ifstream &file) {
    uint32_t s1 = 1, s2 = 0;
    unsigned char cur_byte;
    while (file.read((char *)&cur_byte, sizeof(cur_byte)))
    {
        s1 = (s1 + cur_byte) % 65521;
        s2 = (s1 + s2) % 65521;
    }
    return (s2 << 16u) + s1;
}

uint64_t HashCalc::Sum64(std::ifstream &file) {
    uint64_t result = 0, block = 0;
    uint8_t size = 0;
    unsigned char cur_byte;
    while (file.read((char *)&cur_byte, sizeof(cur_byte)))
    {
        if (size == 8){
            result += block;
            block = 0;
            size = 0;
        }
        block <<= 8u;
        block += cur_byte;
        size++;

    }
    return result + block;
}
