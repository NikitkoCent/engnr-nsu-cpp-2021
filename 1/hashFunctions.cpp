#include "hashFunctions.h"
#include <iostream>
#include <fstream>

#ifdef __linux__
#include <arpa/inet.h>
#endif

#ifdef _WIN32
#include <Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#endif

void adler32(std::ifstream &file){
    uint32_t a = 1, b = 0;
    unsigned char s;
    while (file.read((char *)(&s), sizeof(unsigned char))) {
        a = (a + s) % 65521;
        b = (b + a) % 65521;
    }
    std::cout << std::hex << ((b << 16) | a) << std::endl;
}

void sum64(std::ifstream &file){
    uint64_t contr_sum = 0;
    while (!file.eof()) {
        uint64_t block = 0;
        uint64_t res = 0;
        file.read((char *) &block, sizeof(uint64_t));
        for(int i = 7; i>=0; i--){
            uint64_t bit = block;
            bit >>= (7-i)*8;
            bit <<= 56;
            bit >>= (7-i)*8;
            res += bit;
        }
        if (file.gcount() != 8){
            res >>= 64-8*file.gcount();
        }
        contr_sum += res;
    }
    std::cout << std::hex << contr_sum << std::endl;
}



