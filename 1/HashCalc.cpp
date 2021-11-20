//
// Created by gav on 04/10/2021.
//

#include "HashCalc.h"
#include <cstring>
#include <iostream>

uint32_t HashCalc::adler32(std::ifstream &file) {
    unsigned char tmp;
    uint32_t a = 1, b = 0;

    while (!file.eof()) {
        file.read((char *)&tmp, sizeof(unsigned char));
        std::streamsize bytes = file.gcount();
//        std::cout << "read " << bytes << std::endl;
        if (!bytes) break;

        a = (a + tmp) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}

uint64_t HashCalc::read_uint64(std::ifstream &file) {
    unsigned char tmp;
    uint64_t num = 0, c = 0;

    while (!file.eof() && c < sizeof(uint64_t)){
        file.read((char*)&tmp, sizeof(unsigned char));
        std::streamsize bytes = file.gcount();
        if (!bytes) break;
//        printf("Read one byte: %x\n", tmp);

        num <<= 8; num |= tmp;

        c++;
    }
//    printf("Read one num: %llx\n", num);
    return num;
}

uint64_t HashCalc::sum64(std::ifstream &file) {
    uint64_t sum = 0, tmp;

    while (!file.eof()) {
//        file.read((char*)&tmp, sizeof(uint64_t));
//        std::streamsize bytes = file.gcount();
//        if (!bytes) break;
//        tmp = read_uint64(file);
//        tmp = NTOHLL(tmp);
//        tmp >>= 8 * (8 - abs(bytes));
        tmp = read_uint64(file);
//        printf("read: %llx\n", tmp);
//        printf("read: %llx\n", tmp[0]);
//        tmp[0] = NTOHLL(tmp[0]); // Ensure big-endian
//        printf("after: %llx\n", tmp[0]);

        sum += tmp;
    }
    return sum;
}
