//
// Created by Dasha Shestakova on 13.12.2021.
//

#include "HashCalc.h"

uint32_t HashCalc::Adler32(std::ifstream &file) {
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    char cur_byte;
    while (file.read(&cur_byte, sizeof(cur_byte)))
    {
        s1 = (s1 + cur_byte) % 65521;
        s2 = (s1 + s2) % 65521;
    }
    return (s2 << 16u) + s1;
}

uint64_t HashCalc::Sum64(std::ifstream &file) {
    return 0;
}
