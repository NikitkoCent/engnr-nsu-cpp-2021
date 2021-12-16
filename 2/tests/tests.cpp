#include "../command_processing.h"
#include "gtest/gtest.h"
#include "../libs/SafeInt/SafeInt.hpp"


#include <sstream>

TEST(test1, test_1) {
    std::string filepath = "C:\\Users\\kiril\\CLionProjects\\2lab\\tests\\test_file\\in_1.txt";
    testing::internal::CaptureStdout();
    std::ifstream in(filepath);

    std::string result = "220\n";
    command_processing(in, 2);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test2, test_2) {
    std::string filepath = "C:\\Users\\kiril\\CLionProjects\\2lab\\tests\\test_file\\in_2.txt";
    testing::internal::CaptureStdout();
    std::ifstream in(filepath);

    std::string result = "2\n";
    command_processing(in, 2);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test3, test_3) {
    std::string filepath = "C:\\Users\\kiril\\CLionProjects\\2lab\\tests\\test_file\\in_3.txt";
    testing::internal::CaptureStdout();
    std::ifstream in(filepath);

    std::string result = "18\n";
    command_processing(in, 2);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}

TEST(test4, test_4) {
    std::string filepath = "C:\\Users\\kiril\\CLionProjects\\2lab\\tests\\test_file\\in_4.txt";
    testing::internal::CaptureStdout();
    std::ifstream in(filepath);

    std::string result = "16\n";
    command_processing(in, 2);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    EXPECT_EQ(output, result);
}


TEST(test5, test_5) {
    std::string filepath = "C:\\Users\\kiril\\CLionProjects\\2lab\\tests\\test_file\\in_5.txt";
    testing::internal::CaptureStdout();
    std::ifstream in(filepath);

    std::string result = "300\n";
    command_processing(in, 2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}