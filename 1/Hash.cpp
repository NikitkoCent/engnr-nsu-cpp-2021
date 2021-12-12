//
// Created by Артем Шмаков on 11.12.2021.
//

#include "Hash.h"

uint32_t adler32(std::istream &file) {
    uint32_t a, b;
    a = 1;
    b = 0;
    unsigned char s;
    while (file.read((char *) (&s), sizeof(unsigned char))) {
        a += s % 65521;
        b += a % 65521;
    }
    return ((b << 16) | a);
}

uint64_t sum64(std::istream &file) {
    uint64_t s, b, c;
    s = 0;
    b = 0;
    unsigned char k;
    while (!file.eof()) {
        c = 0;
        while (file.read((char *) (&k), sizeof(unsigned char)) && c < sizeof(unsigned int)) {
            s <<= 8;
            s |= k;
            c++;
        }
        b += s;
    }
    return b;
}
