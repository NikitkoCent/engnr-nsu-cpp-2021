//
// Created by Дарья on 07.01.2022.
//

#include <fstream>
#include "Commands.h"
#include "gtest/gtest.h"

TEST(Calc, example) {
    std::stringstream data("# myVar = -14 / 5\n"
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
                           "PRINT");
    int64_t result = 220;
    StackCalc stack;
    stack = ReadFromFile(data);
    EXPECT_EQ(stack.FindResult()["result"], result);
}

TEST (Calc, test_1) {
    std::stringstream data("PUSH 1\n"
                       "\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "\n"
                       "PUSH 5\n"
                       "\n"
                       "MUL\n"
                       "PRINT");
    int64_t result = 15;
    StackCalc stack;
    stack = ReadFromFile(data);
    EXPECT_EQ(stack.FindResult()["result"], result);
}

TEST(Calc, test_exception_Overflow)  {
    std::stringstream data("PUSH 94073857789372082\n"
                           "PUSH 98493483785029825\n"
                           "PUSH 41684641684615364856\n"
                           "PLUS\n");
    EXPECT_THROW(ReadFromFile(data), OverflowException);
}

TEST(Calc, test_exception_WrongArgument)  {
    std::stringstream data("PUSH 1\n"
                           "PUSH MyVar\n");
    EXPECT_THROW(ReadFromFile(data), WrongArgument);
}

TEST(Calc, test_divisionbyzero) {
    std::stringstream data("PUSH 10\n"
                           "PUSH 0\n"
                           "DIV\n");
    EXPECT_THROW(ReadFromFile(data), DivisionByZero);
}

TEST(Calc, test_exception_Emptystack) {
    std::stringstream data("PUSH 1\n"
                           "PUSH 5\n"
                           "MINUS\n"
                           "POP\n"
                           "POP\n");
    EXPECT_THROW(ReadFromFile(data),EmptyStack);}

TEST(Calc, test_exception_unknown)  {
    std::stringstream data("PUSH 1\n"
                           "Hello\n");
    EXPECT_THROW(ReadFromFile(data), UnknownCommand);}

TEST(Calc, test_exception_div)  {
    std::stringstream data("PUSH -9223372036854775808\n"
                           "PUSH -1\n"
                           "DIV\n"
                           "PRINT");
    EXPECT_THROW(ReadFromFile(data), OverflowException);}

