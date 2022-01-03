#include "calculator.hpp"
TEST(test1, test_1) {
    std::stringstream test ("# myVar = -14 / 5\n"
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
                       "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "220\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}
TEST(test2, test_2) {
    std::string test = "PUSH 5\n";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "5\n";
    Preprocessing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}