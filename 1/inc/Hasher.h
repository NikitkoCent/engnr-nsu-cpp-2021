#pragma once
#include <cstdint>
#include <map>
#include "Status.h"

const uint16_t BUFFER_SIZE = 1024;

uint32_t adler32( std::ifstream&);
uint64_t sum64( std::ifstream&);
Status hashProccessing(const char*, HashMode );


