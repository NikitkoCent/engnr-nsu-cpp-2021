#pragma once
#include <cstdint>
#include <map>
#include "Status.h"

const uint16_t BUFFER_SIZE = 1024;

void adler32(const unsigned char*, uint16_t, uint64_t* );
void sum64(const unsigned char*, uint16_t, uint64_t* );
Status hashProccessing(const char*, HashMode );


