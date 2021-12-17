#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "HashFunc.h"

int main(int args, char* argv[])
{
	std::cout << argv[1] << " " << argv[2] << " " << argv[3] << std::endl;
	programActions actions;
	actions.inputParser(args, argv);
	if (actions.result != -1)
	{
		return actions.result;
	}
	std::string filepath = argv[actions.file];
	int mode = actions.mode;
	std::fstream file;
	std::cout << "HELLO MY DEAR FRIEND1" << mode << filepath << std::endl;
		file.open(filepath, std::ios::binary);
		if (!(file.is_open()))
		{
			std::cout << "Error is here" << std::endl;
			std::cerr << "Program error: file is not found" << std::endl;
			Help();
			return 1;
		}
		std::cout << "HELLO MY DEAR FRIEND3" << std::endl;
		try {
			if (mode == 1)
			{
				std::cout << std::hex << hashpunk::adler32(file) <<  std::endl;
			}
			else if (mode == 2)
			{
				std::cout << std::hex << hashpunk::sum64(file) <<  std::endl;
			}
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		return 0;
}