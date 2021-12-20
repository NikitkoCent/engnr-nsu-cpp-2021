//
// Created by nedobitaia on 18.12.2021.
//

#include "Hash.h"

#include <iostream>
#include <fstream>
#include <cstdint>


uint32_t  Hash::adler32(std::istream &file){
    uint32_t  a = 1, b = 0;
    unsigned char k;
    while( file.read((char *)(&k), sizeof(unsigned char)) ){
        a = ( a + (k) ) % 65521;
        b = ( b + a ) % 65521;
    }
    return ( b << 16 ) | a;
}

uint64_t Hash::sum64(std::istream &file) {
    unsigned char tmp;
    uint64_t sum = 0, num = 0, c = 0;

    while (!file.eof()) {
        num = 0; c = 0;
        while (!file.eof() && c < sizeof(uint64_t)){
            file.read((char*)&tmp, sizeof(unsigned char));
            std::streamsize bytes = file.gcount();
            if (!bytes) break;
            num <<= 8;
            num |= tmp;
            c++;
        }
        sum += num;
    }
    return sum;
}
