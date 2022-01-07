#include <sstream>
#include "../calc.h"
#include <string>

TEST(test1, base_test) {
    std::string test = "# myVar = -14 / 5\n"
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
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "220\n";
    calc_work(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
    EXPECT_EQ(output, result);
}


TEST(test2, ABS_test) {
    std::string test = "PUSH -100\n"
                       "ABS\n"
                       "PUSH 100\n"
                       "DIV\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "1\n";
    calc_work(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}


TEST(test3, just_big_test) {
    std::string test = "PUSH 100\n"
                       "PRINT\n"
                       "\n"
                       "\n"
                       "\n"
                       "PUSH 12\n"
                       "PUSH 13\n"
                       "PRINT\n"
                       "\n"
                       "\n"
                       "MUL\n"
                       "PRINT\n"
                       "\n"
                       "ABS\n"
                       "PRINT\n"
                       "PEEK Artyom\n"
                       "PRINT\n"
                       "PUSH 200\n"
                       "PRINT\n"
                       "PUSH Artyom\n"
                       "PRINT\n"
                       "\n"
                       "PUSH 290\n"
                       "PRINT\n"
                       "\n"
                       "MUL\n"
                       "PRINT\n";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "100\n"
                         "13\n"
                         "156\n"
                         "156\n"
                         "156\n"
                         "200\n"
                         "156\n"
                         "290\n"
                         "45240\n";
    calc_work(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}



TEST(test4, Pop_ex) {
    std::string test = "POP\n";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::Empty);
}

TEST(test5, zero_DIV) {
    std::string test = "PUSH 1\n"
                       "PUSH 3\n"
                       "PUSH 3\n"
                       "MINUS\n"
                       "DIV\n"
                       "PRINT\n";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::DivisionByZero);
}

TEST(test6, Invalid_operation) {
    std::string test = "PUSH 1\n"
                       "PUSH 3\n"
                       "PUK 3\n"
                       "MINUS\n"
                       "DIV\n";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::InvalidOperation);
}

TEST(test7, empty_stack) {
    std::string test = "MINUS\n"
                       "PRINT\n";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::StackEmpty);
}

TEST(test8, stack_deficit) {
    std::string test = "PUSH 1\n"
                       "MINUS\n"
                       "PRINT\n";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::StackDeficit);
}

TEST(test9, very_big_grem) {
    std::string test = "PUSH -9223372036854775808\n"
                       "ABS\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), SafeIntException);
}

TEST(test10, very_big_number_for_push) {
    std::string test = "PUSH 10000000000000000000\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::PushException);
}

TEST(test11, very_big_number_for_mull) {
    std::string test = "PUSH 853373436854\n"
                       "PUSH 20898131\n"
                       "MUL\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::my_overflow);
}

TEST(test12, very_big_number_for_abs) {
    std::string test = "PUSH -9223372036854775808\n"
                       "ABS\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(calc_work(in_s, in, 3), SafeIntException);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}