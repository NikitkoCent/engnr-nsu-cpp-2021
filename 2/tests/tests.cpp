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
            "PUSH var1\n"
            "PUSH var2\n"
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
            "PEEK var\n"
            "PUSH -2\n"
            "MUL\n"
            "PUSH var\n"
            "DIV\n"
            "PRINT");
    testing::internal::CaptureStdout();
    std::ifstream in;
    std::string result = "-2\n";
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
TEST(test6, test_6) {
    std::stringstream test (
            "PUSH 10000000000000000000\n"
            "PRINT\n"
            );
    std::ifstream in;
    EXPECT_THROW(Preprocessing(test, in, 3),  pushexc);
}
TEST(test7, test_7) {
    std::stringstream test (
    "PUSH 853373436854\n"
    "PUSH 20898131\n"
    "MUL\n"
    "PRINT\n"
    );
    std::ifstream in;
    EXPECT_THROW(Preprocessing(test, in, 3),  FatalErr);
}
TEST(test8, test_8) {
    std::stringstream test (
            "PUSH -9223372036854775808\n"
            "ABS\n"
            "PRINT"
    );
    std::ifstream in;
    EXPECT_THROW(Preprocessing(test, in, 3),  FatalErr);
}
TEST(test, test_9) {
    std::stringstream test (
            "PUSH 5\n"
            "PUSH 0\n"
            "DIV\n"
            "PRINT"
    );
    std::ifstream in;
    EXPECT_THROW(Preprocessing(test, in, 3),  DivideByZero);
}