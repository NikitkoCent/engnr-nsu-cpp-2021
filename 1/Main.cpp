#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Adler32.h"
#include "Sum64.h"
#include "Help.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> args(argc);
	for (int i = 0; i < argc; i++)
		args[i] = argv[i];

	if (argc == 2)
	{
		if (args[1] == "-h")
		{
			std::cout << Help::Get();
			return 0;
		}

		std::cerr << "invalid argument: \"" + args[1] + "\", use -h for help";
		return 1;
	}
	else if (argc == 4)
	{
		std::string mode;
		std::string path;

		if (args[1] == "-m")
		{
			mode = args[2];
			path = args[3];
		}
		else
		{
			mode = args[3];
			path = args[1];
		}

		std::ifstream file;
		file.open(path, std::ios::binary);

		if (!file.is_open())
		{
			std::cerr << "cant open file: \"" + path + "\"";
			return 1;
		}

		if (mode == "sum64")
			std::cout << std::hex << Sum64::Use(file);
		else if (mode == "adler32")
			std::cout << std::hex << Adler32::Use(file);
		else
		{
			std::cerr << "invalid mode: \"" + mode + "\", use -h for help";
			return 1;
		}

		return 0;
	}
	else
	{
		std::cerr << "invalid arguments count, use -h for help";
		return 1;
	}
}