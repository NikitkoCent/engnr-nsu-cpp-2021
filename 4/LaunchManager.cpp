#include "LaunchManager.h"

std::string LaunchManager::help = " --help-- ";

int LaunchManager::Launch(int argc, char** argv)
{
	size_t threads = 1;
	if (argc > 1)
	{
		bool invalid = true;
		std::string argOne = argv[1];
		if (argc == 2)
		{
			if (argOne.compare("--help") == 0)
			{
				std::cout << help << std::endl;
				return 0;
			}
		}
		else if((argc == 3) && ((argOne.compare("-t") == 0) || (argOne.compare("--threads") == 0)))
		{
			std::stringstream s;
			s << argv[2];
			s >> threads;
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