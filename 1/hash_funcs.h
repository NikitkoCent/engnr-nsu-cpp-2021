#ifndef HASHER_HASH_FUNCS_H
#define HASHER_HASH_FUNCS_H
#include <fstream>


uint64_t block_to_uint64(const char block[], int64_t length);
uint64_t sum64(std::ifstream &file);
uint32_t adler32(std::ifstream &file);
#endif
