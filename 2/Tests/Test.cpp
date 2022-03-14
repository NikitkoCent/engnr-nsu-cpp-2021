#include <sstream>
#include <fstream>

#include <gtest/gtest.h>

#include "StackCalculator.h"

void stCaclkTest(std::string test, std::string result, std::string err)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::stringstream in_st(test);
    StackCalculator().FromStream(in_st);
    std::string output = testing::internal::GetCapturedStdout();
    std::string errput = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, result);
    EXPECT_EQ(errput, err);
}

TEST(Example, test1)  //опнбепйю деиярбхи
{
    std::string test =
        "# proverka\n"
        "PUSH 15\n"
        "\n"
        "PUSH 3\n"
        "PUSH 2\n"
        "PLUS\n"
        "PRINT\n"
        "DIV\n"
        "PEEK MV\n"
        "PUSH MV\n" 
        "MUL\n"
        "PRINT\n"
        "PUSH 15\n"
        "MINUS\n"
        "PRINT\n"
        "ABS\n"
        "PRINT";
    std::string result = "5\n"
        "9\n"
        "-6\n"
        "6\n";
    std::string err = "";
    stCaclkTest(test, result, err);
}

TEST(MError, EmptyStack)  //осярни ярей
{
    std::string test =
        "PUSH 1\n"
        "PUSH 5\n"
        "POP\n"
        "PLUS\n"
        "PRINT";
    std::string result = "";
    std::string err = "<line: 4> stack was empty\n";
    stCaclkTest(test, result, err);
}

TEST(MError, UnknownCommand1)
{
    std::string test =
        "PUSH 1\n"
        "PUSH 5\n"
        "PRINT\n"
        "POP tyhjhbv\n"
        "PRINT\n"
        "POP";
    std::string result = "5\n1\n";
    std::string err = "";
    stCaclkTest(test, result, err);
}
TEST(MError, div0)  //декемхе мю 0 
{
    std::string test =
        "PUSH 3\n"
        "PUSH 0\n"
        "DIV\n"
        "PRINT";
    std::string result = "";
    std::string err = "<line: 3> overflow\n";
    stCaclkTest(test, result, err);
}

TEST(MError, UnknownCommand2)  //ньхайю б йнлюмде
{
    std::string test =
        "PUSH 8\n"
        "ABS\n"
        "PAP\n"
        "PUSH 9\n"
        "PRINT";
    std::string result = "";
    std::string err = "<line: 3> unknown command: \"PAP\"\n";
    stCaclkTest(test, result, err);
}

TEST(MError, CloseOverflow1)
{
    std::string test =
        "PUSH -9223372036854775808\n"
        "PRINT\n"
        "POP\n";
    std::string result = "-9223372036854775808\n";
    std::string err = "";
    stCaclkTest(test, result, err);
}

TEST(MError, CloseOverflow2)
{
    std::string test =
        "PUSH 9223372036854775807\n"
        "PRINT\n"
        "POP\n";
    std::string result = "9223372036854775807\n";
    std::string err = "";
    stCaclkTest(test, result, err);
}

TEST(MError, Overflow1)
{
    std::string test = "PUSH -9223372036854775809";
    std::string result = "";
    std::string err = "<line: 1> overflow\n";
    stCaclkTest(test, result, err);
}

TEST(MError, Overflow2)
{
    std::string test = "PUSH 9223372036854775808";
    std::string result = "";
    std::string err = "<line: 1> overflow\n";
    stCaclkTest(test, result, err);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
