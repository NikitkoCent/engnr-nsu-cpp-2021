#include <fstream>
#include "../src/commands/StackCalc.h"
#include "gtest/gtest.h"

//TEST(CALCULATOR1, EXAMPLE_TEST) {
//    std::string filepath = "../../tests/test_files/EXAMPLE_TEST";
//    std::ifstream file;
//    file.open(filepath);
//    int64_t result = 220;
//    StackCalc stack;
//    stack = ReadFromStream(file);
//    EXPECT_EQ(stack.FindResult()["result"], result);
//}

//TEST(CALCULATOR1, EASY_TEST) {
//    std::string filepath = "../../tests/test_files/EASY_TEST";
//    std::ifstream file;
//    file.open(filepath);
//    int64_t result = 0;
//    StackCalc stack;
//    stack = ReadFromStream(file);
//    EXPECT_EQ(stack.FindResult()["result"], result);
//}
//
//TEST(CALCULATOR1, HARD_TEST) {
//    std::string filepath = "../../tests/test_files/HARD_TEST";
//    std::ifstream file;
//    file.open(filepath);
//    int64_t result = 16;
//    StackCalc stack;
//    stack = ReadFromStream(file);
//    EXPECT_EQ(stack.FindResult()["result"], result);
//}
//
TEST(CALCULATOR1, COMMAND_LINE_TEST) {
    std::stringstream data("PUSH 234\n"
                           "PUSH 66\n"
                           "PLUS\n"
                           "PUSH 30\n"
                           "DIV\n"
                           "PUSH 1\n"
                           "MUL\n"
                           "PRINT");
    int64_t result = 10;
    StackCalc stack;
    stack = ReadFromStream(data);
    EXPECT_EQ(stack.FindResult()["result"], result);
}
