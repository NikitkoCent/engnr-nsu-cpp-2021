//
// Created by uchansansan on 01.01.2022.
//

#ifndef LAB1_HASHER_H
#define LAB1_HASHER_H

#include <iostream>
#include <fstream>
#include <cstdint>

uint32_t adler32(std::ifstream&);
uint64_t sum64( std::ifstream&);

#endif //LAB1_HASHER_H
