#include "hash.h"

uint32_t adler32(std::istream &file) {
    uint32_t a, b;
    a = 1;
    b = 0;
    unsigned char s;
    while (file.read((char *) (&s), sizeof(unsigned char))) {
        a = ( a + s ) % 65521;
        b = ( b + a ) % 65521;
    }
    return ((b << 16) | a);
}

uint64_t sum64(std::istream &file) {
    uint64_t s, result_sum, count;
    result_sum = 0;
    unsigned char k;
    while (!file.eof()) {
        s = 0;
        count = 0;
        while (count < 8 * sizeof(unsigned char)) {
            file.read((char *) (&k), sizeof(unsigned char));
            if (!file.gcount()) break;
            s <<= 8;
            s |= k & 0xff;
            count++;
        }
        result_sum += s;
    }
    return result_sum;
}