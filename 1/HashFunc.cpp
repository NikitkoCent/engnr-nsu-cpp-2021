#include "HashFunc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

uint32_t hashpunk::adler32(std::istream &file)
{
	uint32_t a = 1, b = 0;
	unsigned char s;
	while (!file.eof())
	{
		file.read((char*)&s, sizeof(unsigned char));
		std::streamsize bytes = file.gcount();
		if (!bytes) break;
		a = (a + s) % 65521;
		b = (b + a) % 65521;
	}
	return ((b << 16) | a);
}

uint64_t hashpunk::sum64(std::istream &file)
{
	uint64_t sum = 0, k = 0;
	int g = 0;
	unsigned char s;
	while (!file.eof())
	{
		file.read((char*)&s, sizeof(unsigned char));
		std::streamsize bytes = file.gcount();
		if (!bytes) break;
		if (g == 7)
		{
			sum += k;
			k = 0;
		}
		k = (k << 8) | s;
		g = (g + 1) % 8;
	}
	if (g != 1)
	{
		sum += k;
	}
	return sum;
}

void Help(int k)
{
	std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";
	if (k)
	{
		std::cerr << help << std::endl;
	}
	else
	{
		std::cout << help << std::endl;
	}

}

programActions::programActions()
{
	mode = -1;
	result = -1;
	file = false;
}

void programActions::inputParser(int args, char* argv[])
{

	if (args == 2 && strcmp(argv[1], "-h") == 0) {
		Help(0);
		result = 0;
	}
	else if (args == 4)
	{
		if (strcmp(argv[1], "-m") == 0)
		{
			if (strcmp(argv[2], "adler32") == 0)
			{
				mode = 1;
				file = 3;
			}
			else if (strcmp(argv[2], "sum64") == 0)
			{
				mode = 2;
				file = 3;
			}
			else
			{
				std::cerr << "Wrong usage: unknown mode" << std::endl;
				Help(1);
				result = 1;
			}
		}
		else if (strcmp(argv[2], "-m") == 0)
		{
			if (strcmp(argv[3], "adler32") == 0)
			{
				mode = 1;
				file = 1;
			}
			else if (strcmp(argv[3], "sum64") == 0)
			{
				mode = 2;
				file = 1;
			}
			else
			{
				std::cerr << "Wrong usage: unknown mode" << std::endl;
				Help(1);
				result = 1;
			}
		}
		else
		{
			std::cerr << "Wrong usage: wrong arguments" << std::endl;
			Help(1);
			result = 1;
		}
	}
	else
	{
		std::cerr << "Wrong usage: unknown commands" << std::endl;
		Help(1);
		result = 1;
	}
}
