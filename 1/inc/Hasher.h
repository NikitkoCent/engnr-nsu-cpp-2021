#pragma once
#include <cstdint>
#include <map>
#include "Status.h"

const uint16_t BUFFER_SIZE = 1024;

uint32_t adler32( unsigned char*, ptrdiff_t);
uint64_t sum64( unsigned char*, ptrdiff_t);
Status hashProccessing(const char*, HashMode );


