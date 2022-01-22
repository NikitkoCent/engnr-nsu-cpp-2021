#pragma once

#include <sstream>
#include <string>

#include "WorkManager.h"

class LaunchManager
{
private:
	static std::string help;
public:
	static int Launch(int argc, char** argv);
};
