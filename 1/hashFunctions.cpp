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
        file.read((char *) &block, sizeof(uint64_t));
//        std::bitset<128> x(block);
//        std::cout << x << " " << file.gcount() <<  std::endl;
        uint64_t res = 0;
        for(int i = 7; i>=0; i--){
            uint64_t blockb = block;
            blockb >>= (7-i)*8;
            blockb <<= 56;
            blockb >>= (7-i)*8;
            res += blockb;
        }
//        block = (((uint64_t)ntohl((block) & 0xFFFFFFFFUL)) << 32) | ntohl((uint32_t)((block) >> 32));
//        std::bitset<128> r(block);
//        std::cout << r << " " << file.gcount() << std::endl;
//        std::bitset<128> y(res);
//        std::cout << y << " res " << file.gcount() << std::endl;
        if (file.gcount() != 8){
            res >>= 64-8*file.gcount();
        }
//        std::bitset<128> z(block);
//        std::cout << z << " " << file.gcount() << std::endl;
        contr_sum += res;
    }
    std::cout << std::hex << contr_sum << std::endl;
}



