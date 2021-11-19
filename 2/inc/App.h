#pragma once

#include <fstream>

#include "Calculator.h"

void proceedNoArgs();
void proceedWithArgs(const char *path);
void calculateNoArgs();
void calculateWithArgs(std::ifstream& ifs);


