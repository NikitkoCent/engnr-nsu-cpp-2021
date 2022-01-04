#include <sstream>
#include "../calc.h"

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

//TEST(test2, common_test) {
//std::string test = "PUSH 190\n"
//                   "PUSH 2"
//                   "MUL\n"
//                   "PUSH 4"
//                   "DIV\n"
//                   "PEEK myVar\n"
//                   "POP\n"
//                   "PUSH myVar\n"
//                   "PUSH 95\n"
//                   "DIV\n"
//                   "PRINT";
//std::stringstream in_s(test);
//std::ifstream in;
//std::string result = "1\n";
//calc_work(in_s, in, 3);
//std::string output = testing::internal::GetCapturedStdout();
//std::cout << output;
//EXPECT_EQ(output, result);
//}

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
calc_work(in_s, in, 3);
std::string output = testing::internal::GetCapturedStdout();
std::cout << output;
EXPECT_EQ(output, result);
}


//TEST(test5, test_5) {
//std::string test = "READ 180\n"
//                   "PUSH 3\n"
//                   "DIV\n"
//                   "PEEK myVAr"
//                   "POP"
//                   "PUSH myVar"
//                   "PRINT";
//testing::internal::CaptureStdout();
//std::stringstream in_s(test);
//std::ifstream in;
//std::string result = "60\n";
//calc_work(in_s, in, 3);
//std::string output = testing::internal::GetCapturedStdout();
//std::cout << output;
//EXPECT_EQ(output, result);
//}

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
calc_work(in_s, in, 3);
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
EXPECT_THROW(calc_work(in_s, in, 3), SafeIntException);
}

TEST(test8, test_8) {
std::string test = "PUSH -9223372036854775808\n"
                   "PEEK\n"
                   "PRINT";
std::stringstream in_s(test);
std::ifstream in;
EXPECT_THROW(calc_work(in_s, in, 3), CalcExceptions::StackDeficit);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}