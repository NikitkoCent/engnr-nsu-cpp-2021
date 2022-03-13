#include "Calculator.h"

int Calculator::Work(std::istream& st)
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