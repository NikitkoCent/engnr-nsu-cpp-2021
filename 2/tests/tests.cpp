#include "../calculator.hpp"
TEST(test1, test_1) {
    std::stringstream test (
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
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "200\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}
TEST(test2, test_2) {
    std::stringstream test (
            "PUSH -100\n"
            "ABS\n"
            "READ 5\n"
            "PLUS\n"
            "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "105\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}
TEST(test3, test_3) {
    std::stringstream test (
            "PUSH 25\n"
            "PEEK var1\n"
            "PUSH 5\n"
            "PLUS\n"
            "PEEK var2\n"
            "PLUS\n"
            "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "55\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}
TEST(test4, test_4) {
    std::stringstream test (
            "PUSH 1\n"
            "PUSH -2\n"
            "MUL\n"
            "DIV\n"
            "POP\n"
            "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "1\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test5, test_5) {
    std::stringstream test (
            "PUSH 1\n"
            "\n"
            "PUSH 2\n"
            "PLUS\n"
            "\n"
            "PUSH 5\n"
            "\n"
            "MUL\n"
            "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "15\n";
    Preprocessing(test, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}