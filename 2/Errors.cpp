//
// Created by Дарья on 06.01.2022.
//
#include "Commands.h"
#include "Operations.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <charconv>
#include <algorithm>

void CustomException::SafeIntOnOverflow() {
    throw OverflowException();


