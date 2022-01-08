#include "hash.h"

uint32_t adler32(std::istream &file) {
    uint32_t a = 1, b = 0;
    unsigned char s;

    while (file.read((char *) (&s), sizeof(unsigned char))) {
        a = (a + s) % 65521;
        b = (b + a) % 65521;
    }

    return ((b << 16) | a);
}

uint64_t sum64(std::istream &file) {
    uint64_t sum_block, sum = 0, c;
    unsigned char k;

    while (!file.eof()) {
        sum_block = 0; c = 0;
        while (c < 8 * sizeof(unsigned char)) {
            file.read((char *) (&k), sizeof(unsigned char));
            if (!file.gcount()) break;
            sum_block <<= 8;
            sum_block |= k & 0xff;
            c++;
        }
        sum += sum_block;
    }

    return sum;
}