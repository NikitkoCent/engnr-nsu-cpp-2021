//
// Created by nedobitaia on 18.12.2021.
//

#include "Hash.h"

#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;


uint32_t  Hash::adler32(istream &file){
    uint32_t  a = 1, b = 0;
    unsigned char k;
    while( file.read((char *)(&k), sizeof(unsigned char)) ){
        a = ( a + (k) ) % 65521;
        b = ( b + a ) % 65521;
    }
    return ( b << 16 ) | a;
}


uint64_t  Hash::read_uint64(istream &file) {
    unsigned char tmp;
    uint64_t num = 0, c = 0;

    while (!file.eof() && c < sizeof(uint64_t)){
        file.read((char*)&tmp, sizeof(unsigned char));
        streamsize bytes = file.gcount();
        if (!bytes) break;
        num <<= 8;
        num |= tmp;
        c++;
    }
    return num;
}

uint64_t Hash::sum64(istream &file) {
    uint64_t sum = 0;
    while (!file.eof())
        sum += read_uint64(file);
    return sum;
}
