#pragma once

#include <fstream>

#include "Calculator.h"

ns_Calc::CalcContext proceedNoArgs();
ns_Calc::CalcContext proceedWithArgs(const char *path);
ns_Calc::CalcContext calculateNoArgs();
ns_Calc::CalcContext calculateWithArgs(std::ifstream& ifs);


