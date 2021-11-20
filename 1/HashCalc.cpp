//
// Created by gav on 04/10/2021.
//

#include "HashCalc.h"
#include <cstring>
#include <iostream>

uint32_t HashCalc::adler32(std::istream &file) {
    unsigned char tmp;
    uint32_t a = 1, b = 0;

    while (!file.eof()) {
        file.read((char *)&tmp, sizeof(unsigned char));
        std::streamsize bytes = file.gcount();
        if (!bytes) break;

        a = (a + tmp) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}

uint64_t HashCalc::read_uint64(std::istream &file) {
    unsigned char tmp;
    uint64_t num = 0, c = 0;

    while (!file.eof() && c < sizeof(uint64_t)){
        file.read((char*)&tmp, sizeof(unsigned char));
        std::streamsize bytes = file.gcount();
        if (!bytes) break;

        num <<= 8; num |= tmp;
        c++;
    }
    return num;
}

uint64_t HashCalc::sum64(std::istream &file) {
    uint64_t sum = 0;

    while (!file.eof())
        sum += read_uint64(file);

    return sum;
}
