#pragma once

#include <fstream>
#include <iostream>
#include "Calculator.h"

ns_Calc::CalcContext proceedNoArgs();
ns_Calc::CalcContext proceedWithArgs(const char *path);
ns_Calc::CalcContext calculate(std::istream& input);


