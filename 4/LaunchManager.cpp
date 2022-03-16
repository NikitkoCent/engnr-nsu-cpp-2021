#include "LaunchManager.h"

std::string LaunchManager::help =
	"\nThis program calculates the size of the specified directories"
	"\n"
	"\nInstructions for use:"
	"\n"
	"\n\twhen you start the program is in input mode mode"
	"\n\tin input mode, the \" > \" sign is displayed in the line"
	"\n"
	"\n\tthe program will go into standby mode"
	"\n\tafter completing the input and pressing \"enter\""
	"\n\tto enter the input mode, you must press \"enter\""
	"\n"
	"\nSpecial commands:"
	"\n"
	"\n\t:exit   = exit program"
	"\n\t:cancel = cancel all waiting tasks"
	"\n\t:help   = call the help"
	"\n"
	"\nOptions:"
	"\n--help             = call help"
	"\n--threads <number> = set number of threads"
	"\n";

int LaunchManager::Launch(int argc, char** argv)
{
	size_t threads = 1;
	if (argc > 1)
	{
		bool invalid = true;
		std::string argOne = argv[1];

		if (argc == 2)
		{
			if ((argOne.compare("-h") == 0) || (argOne.compare("--help") == 0))
			{
				std::cout << help << std::endl;
				return 0;
			}
		}
		else if((argc == 3) && ((argOne.compare("-t") == 0) || (argOne.compare("--threads") == 0)))
		{
			std::stringstream st(argv[2]);
			if (st >> threads)
				invalid = false;
		}

		if (invalid)
		{
			std::cerr << "invalid launch options, use --help";
			return 1;
		}
	}

	auto workManager = WorkManager(threads);
	workManager.Work();

	return 0;
}
