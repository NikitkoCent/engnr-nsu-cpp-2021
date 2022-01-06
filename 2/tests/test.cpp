#include "2\googletest\googletest\include\gtest\gtest.h"
#include "Lab_2.h" 
#include "Lab_2.cpp"

TEST(TestCalc, Test1) {
	std::stringstream input_cmd("# (10 + 5*36)/4 + 15 PRINT"
		"PUSH 10 \n"
		"PUSH 5 \n"
		"PUSH 36 \n"
		"MUL \n"
		"SUM \n"
		"PUSH 4 \n"
		"DIV \n"
		"PUSH 15 \n"
		"SUM \n"
		"PRINT \n");
	int64_t result = 62;
	testing::internal::CaptureStdout();
	std::cout << "PUSH 4";
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, result);
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}