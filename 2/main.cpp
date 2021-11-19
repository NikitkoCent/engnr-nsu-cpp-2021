#include "command_processing.h"
#include "lib/googletest/googletest/include/gtest/gtest.h"
#include "lib/SafeInt/SafeInt.hpp"

#include <sstream>
#include <iostream>

int main() {
    SafeInt<int64_t> res = get_result();
    std::cout << (int)res;
    return 0;
}