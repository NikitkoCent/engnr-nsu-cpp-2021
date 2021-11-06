//
// Created by gav on 04/10/2021.
//

#include "HashCalc.h"
#include <cstring>
#include <iostream>

#ifdef _WIN32
#include <winsock.h>
#else
#include <arpa/inet.h>
#endif

#define HTONLL(x) ((1==htonl(1)) ? (x) : (((uint64_t)htonl((x) & 0xFFFFFFFFUL)) << 32) | htonl((uint32_t)((x) >> 32)))
#define NTOHLL(x) ((1==ntohl(1)) ? (x) : (((uint64_t)ntohl((x) & 0xFFFFFFFFUL)) << 32) | ntohl((uint32_t)((x) >> 32)))

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

uint64_t HashCalc::sum64(std::ifstream &file) {
    uint64_t tmp = 0, sum = 0;

    while (!file.eof()) {
        file.read((char*)&tmp, sizeof(uint64_t));
        std::streamsize bytes = file.gcount();
        if (!bytes) break;

        tmp = NTOHLL(tmp);
        tmp >>= 8 * (8 - abs(bytes));

//        printf("read: %llx\n", tmp[0]);
//        tmp[0] = NTOHLL(tmp[0]); // Ensure big-endian
//        printf("after: %llx\n", tmp[0]);
        sum += tmp;
    }
    return sum;
}
