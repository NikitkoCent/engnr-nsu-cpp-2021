#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "HashFunc.h"

int main(int args, char* argv[])
{
	std::string filepath;
	std::int16_t mode = 0;
	std::string help = "Usage: ./helper -m <mode> <filename> or ./helper <filename> -m <mode> \nMode types: adler32 or sum64";
	std::ifstream file;

	if (args == 2 && strcmp(argv[1], "-h") == 0) {
		std::cout << help << std::endl;
		return 0;
	}
	else if(args == 4)
	{
		if (strcmp(argv[1], "-m") == 0)
		{
			if (strcmp(argv[2], "adler32") == 0)
			{
				mode = 1;
				filepath = argv[3];
			}
			else if (strcmp(argv[2], "sum64") == 0)
			{
				mode = 2;
				filepath = argv[3];
			}
			else
			{
				std::cerr << "Wrong usage: unknown mode" << help << std::endl;
				return 1;
			}
		}
		else if(strcmp(argv[2], "-m") == 0)
		{
			if (strcmp(argv[3], "adler32") == 0)
			{
				mode = 1;
				filepath = argv[1];
			}
			else if (strcmp(argv[3], "sum64") == 0)
			{
				mode = 2;
				filepath = argv[1];
			}
			else
			{
				std::cerr << "Wrong usage: unknown mode" << help << std::endl;
				return 1;
			}
		}
		else
		{
			std::cerr << "Wrong usage: wrong arguments" << help << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "Wrong usage: unknown commands" << help << std::endl;
		return 1;
	}

	 file.open(filepath, std::ios::binary);
	 
	 if (!(file.is_open()))
	 {
		 std::cerr << "Program error: file is not found" << help << std::endl;
		 return 1;
	 }
	 
	 try {
		 if (mode == 1)
		 {
			 std::cout << std::hex << hashpunk::adler32(file) << std::endl;
		 }
		 else if (mode == 2) 
		 {
			 std::cout << std::hex << hashpunk::sum64(file) << std::endl;
		 }
	 }
	 catch (std::exception& e) {
		 std::cerr << e.what() << std::endl;
		 return 1;
	 }
	 return 0;
}