#include <sstream>
#include <fstream>
#include <iostream>

#include <gtest/gtest.h>

#include "Calculator.h"

void CalcTest(std::string input, std::string exp_cout, std::string exp_cerr, int exp_exitcode)
{
	testing::internal::CaptureStderr();
	testing::internal::CaptureStdout();

	std::iostream& st = std::stringstream(input);
	auto exitcode = Calculator::Work(st);
	auto err = testing::internal::GetCapturedStderr();
	auto out = testing::internal::GetCapturedStdout();

	EXPECT_EQ(exitcode, exp_exitcode);
	EXPECT_EQ(out, exp_cout);
	EXPECT_EQ(err, exp_cerr);
}

TEST(CalculatorTest, TaskExample)
{
	auto in =
		"# myVar = -14 / 5"
		"\nPUSH -14"
		"\nPUSH 5"
		"\nDIV"
		"\nPEEK myVar"
		"\nPOP"
		"\n"
		"\n# PRINT(9 - myVar) * 20"
		"\nPUSH 9"
		"\nPUSH myVar"
		"\nMINUS"
		"\nPUSH 20"
		"\nMUL"
		"\nPRINT";

	auto out = "220\n";
	auto err = "";
	auto exitcode = 0;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, EmptyStack)
{
	auto in = "POP";
	auto out = "";
	auto err = "stack empty at 1 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, CloseToOver)
{
	auto in =
		"PUSH 9223372036854775807\n"
		"PUSH -9223372036854775808\n"
		"PRINT\n"
		"POP\n"
		"PRINT";
	auto out =
		"-9223372036854775808\n"
		"9223372036854775807\n";
	auto err = "";
	auto exitcode = 0;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, OverMax)
{
	auto in = 
		"PUSH 9223372036854775808\n"
		"PRINT";;
	auto out = "";
	auto err = "overflow at 1 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, OverMin)
{
	auto in =
		"PUSH -9223372036854775809\n"
		"PRINT";;
	auto out = "";
	auto err = "overflow at 1 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, WrongCommand)
{
	auto in =
		"PUSH 90\n"
		"ABS\n"
		"PAP\n"
		"PUSH 13\n"
		"PRINT";
	auto out = "";
	auto err = "unknown command at 3 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, NullDivide)
{
	auto in =
		"PUSH 3\n"
		"PUSH 0\n"
		"DIV\n"
		"PRINT";
	auto out = "";
	auto err = "overflow at 3 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, WrongArguement)
{
	auto in = "PUSH Myvar";
	auto out = "";
	auto err = "unknown variable at 1 line\n";
	auto exitcode = 1;

	CalcTest(in, out, err, exitcode);
}

TEST(CalculatorTest, SimpleExpression)
{
	auto in = 
		"PUSH 220\n"
		"PUSH 129\n"
		"PUSH 7\n"
		"PRINT";
	auto out = "7\n";
	auto err = "";
	auto exitcode = 0;

	CalcTest(in, out, err, exitcode);
}
