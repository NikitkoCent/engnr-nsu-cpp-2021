#pragma once
#include <iostream>
#include <fstream>

namespace hashpunk
{
	uint32_t adler32(std::fstream&);
	uint64_t sum64(std::fstream&);
}