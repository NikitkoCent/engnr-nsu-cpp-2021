//
// Created by Mikhail Okan on 10.12.2021.
//

#include "googletest/googletest/include/gtest/gtest.h"
#include "StackCalc.h"
#include <iostream>
TEST (test1, test_1) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "PRINT";
    long result = 3;
    std::stringstream in(test);
    calc.execute(in);
    EXPECT_EQ(result, (long)calc.get_last());
}

TEST (test1, test_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 125\n"
                       "PUSH 25\n"
                       "MUL\n"
                       "PUSH 7\n"
                       "DIV\n"
                       "PEEK myVar\n"
                       "PUSH 4\n"
                       "MUL\n"
                       "PUSH myVar\n"
                       "DIV\n"
                       "PUSH -1\n"
                       "MUL\n"
                       "ABS\n"
                       "PRINT";
    long result = 4;
    std::stringstream in(test);
    calc.execute(in);
    EXPECT_EQ(result, (long)calc.get_last());
}

TEST (test1, test_3) {
    SC::StackCalc calc;
    std::string test = "# myVar = -14 / 5\n"
                       "PUSH -14\n"
                       "PUSH 5\n"
                       "DIV\n"
                       "PEEK myVar\n"
                       "POP\n"
                       "# PRINT (9 - myVar) * 20\n"
                       "PUSH 9\n"
                       "PUSH myVar\n"
                       "MINUS\n"
                       "PUSH 20\n"
                       "MUL\n"
                       "PRINT";
    long result = 220;
    std::stringstream in(test);
    calc.execute(in);
    EXPECT_EQ(result, (long)calc.get_last());
}

TEST (test1, test_4) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "PUSH 5\n"
                       "MUL\n"
                       "PRINT";
    long result = 15;
    std::stringstream in(test);
    calc.execute(in);
    EXPECT_EQ(result, (long)calc.get_last());
}