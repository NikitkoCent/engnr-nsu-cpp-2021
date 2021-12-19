//
// Created by Дарья on 14.12.2021.
//
#include "HashFunc.h"
#include <iostream>

using std:: istream;


uint32_t adler32(istream &file){
    uint32_t a = 1, b = 0;  //from wiki
    unsigned char s;
    while (file.read((char *)(&s), sizeof(unsigned char))) {
        a = (a + s) % 65521;
        b = (b + a) % 65521;
    }
    return ((b << 16) | a);
}

uint64_t sum64(istream &file){
    uint64_t result = 0, block = 0;
    uint8_t size = 0;
    unsigned char current_b;
    while (!file.eof()){
        file.read((char *)&current_b, sizeof(unsigned char));
        if (size == 8){
            result += block;
            size = 0;
            block = 0;

        }
        block = block << 8;
        block += current_b;
        size = size+1;

    }
    return result + block;
}

