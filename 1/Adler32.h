#pragma once

#include <cstdint>
#include <istream>

class Adler32
{
public:
	static uint32_t Use(std::istream& file);
};
