//
// Created by Dasha Shestakova on 13.12.2021.
//

#ifndef HASHER_HASHCALC_H
#define HASHER_HASHCALC_H
#include <fstream>
#include <cstdint>

class HashCalc {
public:
    static uint32_t Adler32(std::ifstream &file);
    static uint64_t Sum64(std::ifstream &file);
};


#endif //HASHER_HASHCALC_H
