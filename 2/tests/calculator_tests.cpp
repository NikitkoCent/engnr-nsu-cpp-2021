#include <gtest/gtest.h>

#include "../inc/App.h"
#include "../inc/Calculator.h"

TEST(Calc_Test, Test_Simple)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../tests/test1.txt");
    ASSERT_EQ(220, calc.m_stack.top());
}

TEST(Calc_Test, Test_Medium_1)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../tests/test2.txt");
    ASSERT_EQ(2, calc.m_stack.top());
}

TEST(Calc_Test, Test_Medium_2)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../tests/test3.txt");
    ASSERT_EQ(18, calc.m_stack.top());
}

TEST(Calc_Test, Test_Hard)
{
    ns_Calc::CalcContext calc =proceedWithArgs("../tests/test4.txt");
    ASSERT_EQ(16, calc.m_stack.top());
}

TEST(Calc_Test, Test_Read)
{
    ns_Calc::CalcContext calc = proceedWithArgs("../tests/test5.txt");
    ASSERT_EQ(300, calc.m_stack.top());
}