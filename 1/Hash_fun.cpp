//
// Created by bulga on 18.12.2021.
//

#include "Hash_fun.h"
uint64_t Hashing::read_int(std::istream &file) {
    char temp;
    uint64_t num = 0, count = 0;

    while (!file.eof() && count < sizeof(uint64_t)){
        file.read((char*)&temp, sizeof(char));
        std::streamsize bytes = file.gcount();
        if (!bytes) break;

        num <<= 8; num |= temp;
        count++;
    }
    return num;
}
uint32_t Hashing::adler32(std::ifstream& file) {
    char temp;
    uint32_t a = 1, b = 0;

    while (!file.eof()) {
        file.read((char *)&temp, sizeof(char));
        std::streamsize count = file.gcount();

        a = (a + temp) % mod_adler;
        b = (b + a) % mod_adler;
    }

    return (b << 16) | a;
}


uint64_t Hashing::sum64(std::ifstream& file) {
    uint64_t sum = 0;

    while (!file.eof())
        sum += read_int(file);

    return sum;
}
