#include "../command_processing.h"

#include <sstream>

TEST(test1, test_1) {
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
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test2, test_2) {
    std::string test = "# myVar = 90\n"
                       "PUSH -90\n"
                       "PUSH 1\n"
                       "MUL\n"
                       "ABS\n"
                       "PEEK myVar\n"
                       "# PRINT 90 / 45\n"
                       "POP\n"
                       "PUSH myVar\n"
                       "PUSH 45\n"
                       "DIV\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "2\n";
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test3, test_3) {
    std::string test = "PUSH -72\n"
                       "ABS\n"
                       "PUSH 4\n"
                       "DIV\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "18\n";
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test4, test_4) {
    std::string test = "# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2\n"
                       "# (a + c) * d - e / (f - g) = 16\n"
                       "\n"
                       "PUSH 4\n"
                       "PEEK a\n"
                       "POP\n"
                       "\n"
                       "PUSH 6\n"
                       "PEEK c\n"
                       "POP\n"
                       "\n"
                       "PUSH 2\n"
                       "PEEK d\n"
                       "POP\n"
                       "\n"
                       "PUSH 36\n"
                       "PEEK e\n"
                       "POP\n"
                       "\n"
                       "PUSH 11\n"
                       "PEEK f\n"
                       "POP\n"
                       "\n"
                       "PUSH 2\n"
                       "PEEK g\n"
                       "POP\n"
                       "\n"
                       "\n"
                       "PUSH a\n"
                       "PUSH c\n"
                       "\n"
                       "PLUS\n"
                       "\n"
                       "PUSH d\n"
                       "\n"
                       "MUL\n"
                       "\n"
                       "PUSH e\n"
                       "\n"
                       "PUSH f\n"
                       "PUSH g\n"
                       "\n"
                       "MINUS\n"
                       "\n"
                       "DIV\n"
                       "\n"
                       "MINUS\n"
                       "\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "16\n";
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}


TEST(test5, test_5) {
    std::string test = "READ 234\n"
                       "PUSH 66\n"
                       "PLUS\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "300\n";
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test6, test_6) {
    std::string test = "PUSH -90\n"
                       "PRINT\n"
                       "\n"
                       "PUSH 1\n"
                       "PRINT\n"
                       "\n"
                       "MUL\n"
                       "PRINT\n"
                       "\n"
                       "ABS\n"
                       "PRINT\n"
                       "\n"
                       "PEEK myVar\n"
                       "PRINT\n"
                       "\n"
                       "POP\n"
                       "\n"
                       "PUSH myVar\n"
                       "PRINT\n"
                       "\n"
                       "PUSH 45\n"
                       "PRINT\n"
                       "\n"
                       "DIV\n"
                       "PRINT";
    testing::internal::CaptureStdout();
    std::stringstream in_s(test);
    std::ifstream in;
    std::string result = "-90\n"
                         "1\n"
                         "-90\n"
                         "90\n"
                         "90\n"
                         "90\n"
                         "45\n"
                         "2\n";
    command_processing(in_s, in, 3);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}


TEST(test7, test_7) {
    std::string test = "PUSH -9223372036854775808\n"
                       "ABS\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(command_processing(in_s, in, 3), SafeIntException);
}

TEST(test8, test_8) {
    std::string test = "PUSH -9223372036854775808\n"
                       "PEEK\n"
                       "PRINT";
    std::stringstream in_s(test);
    std::ifstream in;
    EXPECT_THROW(command_processing(in_s, in, 3), PeekEmptyStack);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}