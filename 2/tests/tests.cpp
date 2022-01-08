#include "../src/commands/Command.h"
#include "../src/commands/Exceptions.h"
#include "gtest/gtest.h"

TEST(CALCULATOR1, EXAMPLE_TEST) {
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
    string result = "220\n";
    std::ostringstream oss;
    Context context(oss);
    parse_stream(data, context);
    EXPECT_EQ(oss.str(), result);
}

TEST(CALCULATOR1, DOUBLE_PRINT) {
    std::stringstream data("PUSH 100\n"
                           "PRINT\n"
                           "PRINT");
    string result = "100\n100\n";
    std::ostringstream oss;
    Context context(oss);
    parse_stream(data, context);
    EXPECT_EQ(oss.str(), result);
}

TEST(CALCULATOR1, EASY_PRINT) {
    std::stringstream data("PUSH 10\n"
                           "PRINT");
    string result = "10\n";
    std::ostringstream oss;
    Context context(oss);
    parse_stream(data, context);
    EXPECT_EQ(oss.str(), result);
}


TEST(CALCULATOR1, ERROR_TEST) {
    std::stringstream data("PUSH 1\n"
                           "PUSH 5\n"
                           "PLUS\n"
                           "POP\n"
                           "POP");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), EmptyStack);

}

TEST(CALCULATOR1, DIVISION_BY_ZERO) {
    std::stringstream data("PUSH 1\n"
                           "PUSH 0\n"
                           "DIV");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), DivideByZero);

}

TEST(CALCULATOR1, UNKNOWN_COMMAND) {
    std::stringstream data("DEV");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), UnknownArgument);

}

TEST(CALCULATOR1, EmptyStack) {
    std::stringstream data("PUSH 20\n"
                           "PUSH 6\n"
                           "POP\n"
                           "POP\n"
                           "POP");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), EmptyStack);

}

TEST(CALCULATOR1, WrongArgument) {
    std::stringstream data("PUSH myVar");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), WrongArgument);

}

TEST(CALCULATOR1, ArithmeticalOverflow1) {
    std::stringstream data("PUSH 853373436854\n"
                           "PUSH 20898131\n"
                           "MUL\n"
                           "PRINT");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), SafeIntException);
}

TEST(CALCULATOR1, ArithmeticalOverflow2) {
    std::stringstream data("PUSH -9223372036854775808\n"
                           "ABS\n"
                           "PRINT");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), SafeIntException);
}

TEST(CALCULATOR1, ArithmeticalOverflow3) {
    std::stringstream data("PUSH 10000000000000000000\n"
                           "PRINT");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), WrongArgument);
}

TEST(CALCULATOR1, ArithmeticalOverflow4) {
    std::stringstream data("PUSH -9223372036854775808\n"
                           "PUSH -1\n"
                           "DIV\n"
                           "PRINT");
    std::ostringstream oss;
    Context context(oss);
    EXPECT_THROW(parse_stream(data, context), ArithmeticalError);
}