#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>

#include "Calculator.h"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream fs(argv[1]);
		if (!fs.is_open())
		{
			std::cerr << "cant open file";
			return 1;
		}
		return Calculator::Work(fs);
	}
	else if (argc != 1)
	{
		std::cerr << "invalid arguments";
		return 1;
	}

	return Calculator::Work(std::cin);
}