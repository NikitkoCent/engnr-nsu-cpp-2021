#pragma once
#include <iostream>
#include <fstream>

namespace hashpunk
{
	uint32_t adler32(std::istream&);
	uint64_t sum64(std::istream&);
}