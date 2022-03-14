#include <iostream>
#include <fstream>

#include "Calculator.h"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream fs(argv[1]);
		if (!fs.is_open())
		{
			std::cerr << "cant open file" << std::endl;
			return 1;
		}
		return Calculator::Work(fs);
	}
	else if (argc != 1)
	{
		std::cerr << "invalid arguments" << std::endl;
		return 1;
	}

	return Calculator::Work(std::cin);
}
