#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "OperationHandler.h"

class StackCalculator
{
private:
	int FromStream(std::istream& st);
	OperationHandler ops;
	Memory mem;
public:
	int Run(int argc, char* argv[]);
};
