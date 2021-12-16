﻿#pragma once
#include <iostream>
#include <fstream>

uint32_t adler32(std::istream& file);
uint64_t sum64(std::istream& file);