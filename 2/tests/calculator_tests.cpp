#include <gtest/gtest.h>
#include <sstream>

#include "../inc/App.h"
#include "../inc/Calculator.h"

TEST(Calc_Test, Test_Simple)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../../tests/test1.txt");
    ASSERT_EQ(220, calc.m_stack.top());
}

TEST(Calc_Test, Test_Medium_1)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../../tests/test2.txt");
    ASSERT_EQ(2, calc.m_stack.top());
}

TEST(Calc_Test, Test_Medium_2)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../../tests/test3.txt");
    ASSERT_EQ(18, calc.m_stack.top());
}

TEST(Calc_Test, Test_Hard)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../../tests/test4.txt");
    ASSERT_EQ(16, calc.m_stack.top());
}
TEST(Calc_Test, User_Input_Test)
{
    std::istringstream ss("PUSH 14\nPUSH 15\nMUL\nPRINT\n");

    ns_Calc::CalcContext calc = proceedNoArgs(ss);
}

TEST(Calc_Test, Test_Exception)
{
    EXPECT_THROW(
        {
            try
            {
                ns_Calc::CalcContext calc = proceedWithArgs("../../tests/test5.txt");
            }
            catch (const std::runtime_error &e)
            {
                EXPECT_STREQ("Stack is empty", e.what());
                throw;
            }
        },
        std::runtime_error);
}

TEST(Calc_Test, Test_Exception_Peek)
{
    EXPECT_THROW(
        {
            try
            {
                std::istringstream ss("PEEK");
                ns_Calc::CalcContext calc = proceedNoArgs(ss);
            }
            catch (const std::runtime_error &e)
            {
                EXPECT_STREQ("Required 2 arguements\nError was occured in 1 line: PEEK", e.what());
                throw;
            }
        },
        std::runtime_error);
}

TEST(Calc_Test, Test_Exception_Push)
{
    EXPECT_THROW(
        {
            try
            {
                std::istringstream ss("PUSH ");
                ns_Calc::CalcContext calc = proceedNoArgs(ss);
            }
            catch (const std::runtime_error &e)
            {
                EXPECT_STREQ("Required 2 arguements\nError was occured in 1 line: PUSH ", e.what());
                throw;
            }
        },
        std::runtime_error);
}
