#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>

#include "Command.h"
#include "PeekCommand.h"
#include "MemStack.h"

int work(std::istream& st)
{
	uint32_t counter = 0;
	MemStack mem;
	PeekCommand pk(mem);

	std::string line;
	while (std::getline(st, line))
	{
		counter += 1;

		std::stringstream sst(line);
		std::string command;
		std::string arg;

		sst >> command;

		if (command.empty())
			continue;

		std::getline(sst, arg);

		try
		{
			pk.Get(command).get()->Work(arg);
		}
		catch (Errors& err)
		{
			std::cerr << err.Text() << " at " << counter << " line";
			return 1;
		}
	}

	return 0;
}

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
		return work(fs);
	}
	else if (argc != 1)
	{
		std::cerr << "invalid arguments";
		return 1;
	}

	return work(std::cin);
}