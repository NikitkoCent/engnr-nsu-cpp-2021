//
// Created by gav on 04/10/2021.
//

#ifndef CPP_LABS_HASHCALC_H
#define CPP_LABS_HASHCALC_H

#include <fstream>

#define MOD_ADLER 65521

class HashCalc {
public:
    static uint32_t adler32(std::ifstream &file);
    static uint64_t sum64(std::ifstream &file);
};


#endif //CPP_LABS_HASHCALC_H
