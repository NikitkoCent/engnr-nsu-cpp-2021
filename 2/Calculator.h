#pragma once

#include <istream>

#include "Command.h"
#include "PeekCommand.h"
#include "MemStack.h"

class Calculator
{
public:
	static int Work(std::istream& st);
};

