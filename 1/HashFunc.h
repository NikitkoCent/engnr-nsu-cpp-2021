//
// Created by Дарья on 14.12.2021.
//

#ifndef CPP_LABS_HASHFUNC_H
#define CPP_LABS_HASHFUNC_H
#include <iostream>
using std::istream;

uint32_t adler32(istream &file);
uint64_t sum64(istream &file);

#endif //CPP_LABS_HASHFUNC_H
