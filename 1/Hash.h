//
// Created by nedobitaia on 18.12.2021.
//

#ifndef UNTITLED15_HASH_H
#define UNTITLED15_HASH_H

#include <fstream>
#include <cstdint>
#include <iostream>


class Hash {
public:
    static uint32_t adler32(istream &file);
    static uint64_t sum64(istream &file);
};


#endif //UNTITLED15_HASH_H
