#pragma once

#include "Calculator.h"
#include "libs/SafeInt/SafeInt.hpp"
#include "gtest/gtest.h"

#include <cstdint>
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>

void command_processing(std::stringstream& in_s, std::ifstream& in, int args);