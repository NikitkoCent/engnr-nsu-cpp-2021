//
// Created by zmazerlord on 07.01.2022.
//

#include "funk_adl_sum.h"
#include <iostream>

using namespace std;

uint32_t adler32(ifstream &file) {
    uint32_t a = 1;
    uint32_t b = 0;
    unsigned char buf;
    while (file.read((char *) &buf, sizeof(buf))) {
        a = (a + buf) % 65521;
        b = (b + a) % 65521;
    }
    uint32_t result = (b << 16u) | a;
    return result;
}

uint64_t sum64(ifstream &file) {
    uint64_t result = 0, block = 0;
    uint8_t size = 0;
    unsigned char buf;
    while (file.read((char *) &buf, sizeof(buf))) {
        if (size == 8) {
            result += block;
            block = 0;
            size = 0;
        }
        block <<= 8u;
        block += buf;
        size++;
    }
    result += block;
    return result;
}
