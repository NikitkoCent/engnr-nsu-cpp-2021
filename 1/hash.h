#pragma once

#include <iostream>
#include <fstream>

uint64_t sum64(std::ifstream &file);
uint32_t adler32(std::ifstream& file);