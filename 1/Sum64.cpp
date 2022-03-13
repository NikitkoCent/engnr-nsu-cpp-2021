#include "Sum64.h"

uint64_t Sum64::Use(std::istream& file)
{
	uint64_t result = 0;
	uint64_t block = 0;
	size_t size = 0;
	unsigned char byte;

	while (file >> byte)
	{
		block = (block << 8) | byte;
		size += 1;
		if (size == 8)
		{
			result += block;
			block = 0;
			size = 0;
		}
	}

	return result + block;
}