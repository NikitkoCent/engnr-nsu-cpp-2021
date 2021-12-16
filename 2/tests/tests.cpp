#include "../command_processing.h"
#include "gtest/gtest.h"
#include "../libs/SafeInt/SafeInt.hpp"

#include <sstream>

TEST(test1, test_1) {
    std::string commands = "# myVar = -14 / 5\n"
                           "PUSH -14\n"
                           "PUSH 5\n"
                           "DIV\n"
                           "PEEK myVar\n"
                           "# PRINT (9 - myVar) * 20\n"
                           "POP\n"
                           "PUSH 9\n"
                           "PUSH myVar\n"
                           "MINUS\n"
                           "PUSH 20\n"
                           "MUL\n"
                           "PRINT";
    std::ifstream in(commands.c_str());
    std::string result = "220\n";
    command_processing(in, 2);
    std::ostringstream res(result);
    EXPECT_EQ(result, res.str());
}

TEST(test2, test_2) {
std::string commands = "# myVar = 90 \n"
                       "PUSH -90\n"
                       "PUSH 1\n"
                       "MUL\n"
                       "ABS\n"
                       "PEEK myVar\n"
                       "# PRINT 90 / 45\n"
                       "POP\n"
                       "PUSH myVar\n"
                       "PUSH 45\n"
                       "DIV\n"
                       "PRINT";
    std::ifstream in(commands.c_str());
    std::string result = "2\n";
    command_processing(in, 2);
    std::ostringstream res(result);
    EXPECT_EQ(result, res.str());
}

TEST(test3, test_3) {
std::string commands = "PUSH -72\n"
                       "ABS\n"
                       "PUSH 4\n"
                       "DIV\n"
                       "PRINT";
    std::ifstream in(commands.c_str());
    std::string result = "18\n";
    command_processing(in, 2);
    std::ostringstream res(result);
    EXPECT_EQ(result, res.str());
}

TEST(test4, test_4) {
std::string commands = "# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2\n"
                       "# (a + c) * d - e / (f - g) = 16\n"

                       "PUSH 4\n"
                       "PEEK a\n"
                       "POP\n"

                       "PUSH 6\n"
                       "PEEK c\n"
                       "POP\n"

                       "PUSH 2\n"
                       "PEEK d\n"
                       "POP\n"

                       "PUSH 36\n"
                       "PEEK e\n"
                       "POP\n"

                       "PUSH 11\n"
                       "PEEK f\n"
                       "POP\n"

                       "PUSH 2\n"
                       "PEEK g\n"
                       "POP\n"


                       "PUSH a\n"
                       "PUSH c\n"

                       "PLUS\n"

                       "PUSH d\n"

                       "MUL\n"

                       "PUSH e\n"

                       "PUSH f\n"
                       "PUSH g\n"

                       "MINUS\n"

                       "DIV\n"

                       "MINUS\n"

                       "PRINT";
    std::ifstream in(commands.c_str());
    std::string result = "16\n";
    command_processing(in, 2);
    std::ostringstream res(result);
    EXPECT_EQ(result, res.str());
}


TEST(test5, test_5) {
std::string commands = "READ 234\n"
                       "PUSH 66\n"
                       "PLUS\n"
                       "PRINT";
    std::ifstream in(commands.c_str());
    std::string result = "300\n";
    command_processing(in, 2);
    std::ostringstream res(result);
    EXPECT_EQ(result, res.str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}