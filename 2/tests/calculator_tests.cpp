#include <gtest/gtest.h>
#include <sstream>

#include "../inc/App.h"
#include "../inc/Calculator.h"
#include "../inc/exceptions.h"

TEST(Calc_Test, Simple_1)
{
    std::stringstream test(
        "PUSH 10\n"
        "PUSH 5\n"
        "DIV\n"
        "PEEK myVar\n"
        "POP\n"
        "PUSH 12\n"
        "PUSH myVar\n"
        "MINUS\n"
        "PUSH 20\n"
        "MUL\n"
        "PRINT");

    int64_t res = proceedNoArgs(test).m_stack.top();
    ASSERT_EQ(res, 200);
}

TEST(Calc_Test, Simple_2)
{
    std::stringstream test(
        "PUSH 25 \n"
        "PEEK var1 \n"
        "PUSH 5 \n"
        "PLUS \n"
        "PUSH var1 \n"
        "PLUS \n"
        "PRINT");

    int64_t res = proceedNoArgs(test).m_stack.top();
    ASSERT_EQ(res, 55);
}

TEST(Calc_Test, DivByZero)
{
    std::stringstream test(
        "PUSH 1\n"
        "PUSH 0\n"
        "DIV\n"
        "PRINT");

    EXPECT_THROW({
        try
        {
            proceedNoArgs(test);
        }
        catch( const CalcRuntimeExc& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("Runtime Error was occured in line 3\nDivision by zero\n", e.what() );
            throw;
        }
    },  CalcRuntimeExc); 
}

TEST(Calc_Test, Empty_File)
{
    std::stringstream test("");
    int res = proceedNoArgs(test).m_stack.size();
    ASSERT_EQ(res == 0, true);
}

TEST(Calc_Test, Tokens_3)
{
    std::stringstream test("PUSH 23 extratoken");
    EXPECT_THROW({
        try
        {
            proceedNoArgs(test);
        }
        catch( const CalcInputExc& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("Input error was occured in line 1\nError line : PUSH 23 extratoken\nRequired 2 arguements\n", e.what() );
            throw;
        }
    },  CalcInputExc); 
}