//
// Created by Артем Шмаков on 11.12.2021.
//

#include "Hash.h"

uint32_t adler32(std::istream &file) {
    uint32_t a, b;
    a = 1;
    b = 0;
    unsigned char s;
    while (!file.eof()) {
        file.read((char *) (&s), sizeof(unsigned char));
        std::streamsize v = file.gcount();
        if (!v) break;
        a += s % 65521;
        b += a % 65521;
    }
    return ((b << 16) | a);
}

uint64_t sum64(std::istream &file) {
    uint64_t s, b, c;
    b = 0;
    unsigned char k;
    while (!file.eof()) {
        s = 0;
        c = 0;
        while (c < 8 * sizeof(unsigned char)) {
            file.read((char *) (&k), sizeof(unsigned char));
            if (!file.gcount()) break;
            s <<= 8;
            s |= k & 0xff;
            c++;
        }
        b += s;
    }
    return b;
}
