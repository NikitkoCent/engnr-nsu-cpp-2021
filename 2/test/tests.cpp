//
// Created by nedobitaia on 08.01.2022.
//
#include "../Calc.h"
#include <sstream>
#include <fstream>
#include "gtest/gtest.h"



TEST(test1, test_1) { //ПРОВЕРКА ДЕЙСТВИЙ
std::string test = "# proverka\n"
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
testing::internal::CaptureStdout();
std::stringstream in_s(test);
std::ifstream in;
std::string result = "5\n"
                     "9\n"
                     "-6\n"
                     "6\n";
counting(in_s, in, 3);
std::string output = testing::internal::GetCapturedStdout();
std::cout << output;
EXPECT_EQ(output, result);
}

TEST(test2, test_2) { //ПУСТОЙ СТЕК
std::string test = "PUSH 1\n"
                   "PUSH 5\n"
                   "POP\n"
                   "PLUS\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), PlusException);
}

TEST(test3, test_3) { //ПУСТАЯ ПЕРЕМЕННАЯ
std::string test = "PUSH 6\n"
                   "PUSH 2\n"
                   "PUSH\n"
                   "DIV\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), VarnameException);
}

TEST(test4, test_4) { //ДЕЛЕНИЕ НА 0
std::string test = "PUSH 3\n"
                   "PUSH 0\n"
                   "DIV\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), ZeroException);
}

TEST(test5, test_5) { //ПЕРЕПОЛНЕНИЕ 1
std::string test = "PUSH 99999999999999999999\n"
                   "PUSH 0\n"
                   "DIV\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), SIException);
}

TEST(test6, test_6) { //ПЕРЕПОЛНЕНИЕ 2
std::string test = "PUSH -9223372036854775808\n"
                   "ABS\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), SIException);
}

TEST(test7, test_7) { //ОШИБКА В КОМАНДЕ
std::string test = "PUSH 8\n"
                   "ABS\n"
                   "PAP\n"
                   "PUSH 9\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(counting(in_s, in, 3), CommandException);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

