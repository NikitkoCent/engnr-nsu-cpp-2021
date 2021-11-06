//
// Created by gav on 04/10/2021.
//

#include "HashCalc.h"

uint32_t HashCalc::adler32(std::ifstream &file) {
    char tmp;
    uint32_t a = 1, b = 0;

    while (!file.eof()) {
        file.read(&tmp, sizeof(char));
        a = (a + tmp) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}

uint64_t HashCalc::sum64(std::ifstream &file) {
    uint64_t tmp = 0, sum = 0;

    while (!file.eof()) {
        file.read((char*)&tmp, sizeof(uint64_t));
        tmp = htonll(tmp); // Ensure big-endian
        sum += tmp;
    }
    return sum;
}
