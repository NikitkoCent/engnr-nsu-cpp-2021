#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "OperationHandler.h"

class StackCalculator
{
private:
	OperationHandler ops;
	Memory mem;
public:
	int FromStream(std::istream& st);
	int Run(int argc, char* argv[]);
};
