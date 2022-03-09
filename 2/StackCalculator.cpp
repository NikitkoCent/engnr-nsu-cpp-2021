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
			std::istringstream sst(line);

			sst >> command;
			std::getline(sst >> std::ws, args);

			if (command == "")
				continue;

			ops.Get(command).get()->Use(mem, args);
		}

		return 0;
	}
	catch (MError& err)
	{
		std::cerr << "<line: " << counter << "> " << err.ErrorText();
		return 1;
	}
	catch (...)
	{
		std::cerr << "<line: " << counter << "> " << UnexpectedError().ErrorText();
		return 1;
	}
}

int StackCalculator::Run(int argc, char* argv[])
{
	if (argc != 1)
	{
		std::fstream fs;
		fs.open(argv[1], std::fstream::in);
		if (fs.is_open())
			return FromStream(fs);

		std::cerr << FileError(argv[1]).ErrorText();
		return 1;
	}
	else if (argc == 1)
		return FromStream(std::cin);

	std::cerr << "invalid args";
	return 1;
}
