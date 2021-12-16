#include "HashFunc.h"
#include <iostream>
#include <fstream>

uint32_t adler32(std::istream& file)
{
	uint32_t a = 1, b = 0;
	unsigned char s;
	while (file.read((char*)&s, sizeof(unsigned char)))
	{
		a = (a + s) % 65521;
		b = (b + a) % 65521;
	}
	return ((b << 16) | a);
};

uint64_t sum64(std::istream& file)
{
	uint64_t sum = 0, k = 0;
	int g = 0;
	unsigned char s;
	while (file.read((char*)&s, sizeof(unsigned char)))
	{
		if (g == 7)
		{
			sum += k;
			k = 0;
		}
		k = (k << 8) | s;
		g = (g + 1) % 8;
	}
	if (g != 0)
	{
		sum += k;
	}
	return sum;
};