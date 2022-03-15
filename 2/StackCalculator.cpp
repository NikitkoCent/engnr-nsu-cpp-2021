#include "StackCalculator.h"

int StackCalculator::FromStream(std::istream& st)
{
	int counter = 1;
	try
	{
		std::string line;
		for (; std::getline(st, line); counter++)
		{
			std::string command;
			std::string args;
			std::stringstream sst(line);

			sst >> command;
			std::getline(sst >> std::ws, args);

			if (command.empty())
				continue;

			ops.Get(command)->Use(mem, args);
		}
		return 0;
	}
	catch (MError& err)
	{
		std::cerr << "<line: " << counter << "> " << err.ErrorText() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "<line: " << counter << "> " << UnexpectedError().ErrorText() << std::endl;
		return 1;
	}
}

int StackCalculator::Run(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream fs(argv[1]);
		if (fs.is_open())
			return FromStream(fs);

		std::cerr << FileError(argv[1]).ErrorText() << std::endl;
		return 1;
	}
	else if (argc == 1)
		return FromStream(std::cin);

	std::cerr << InvalidArgs().ErrorText() << std::endl;
	return 1;
}
