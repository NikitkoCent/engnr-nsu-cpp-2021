// CMakeProject1.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <cstdint>
#include <cstring>

std::uint16_t adler32(std::ifstream& file);
std::uint64_t sum64(std::ifstream& file);

