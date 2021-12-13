//#include "command_processing.h"
//#include "lib/googletest/googletest/include/gtest/gtest.h"
//
//#include <sstream>
//
//
//TEST(test1, test_1) {
//    std::vector<std::string> commands = {"# myVar = -14 / 5 ",
//                                         "PUSH -14 ",
//                                         "PUSH 5 ",
//                                         "DIV ",
//                                         "PEEK myVar ",
//                                         "# PRINT (9 - myVar) * 20 ",
//                                         "POP ",
//                                         "PUSH 9 ",
//                                         "PUSH myVar ",
//                                         "MINUS ",
//                                         "PUSH 20 ",
//                                         "MUL ",
//                                         "PRINT"};
//    command_processing();
//
//    std::string expect_result("# myVar = -14 / 5 \n# PRINT (9 - myVar) * 20 \n220\n");
//
//    EXPECT_EQ(expect_result, std::cout);
//}
////
////TEST(test1, test_1) {
////    std::vector<std::string> commands = {"# myVar = -14 / 5 ",
////                                         "PUSH -14 ",
////                                         "PUSH 5 ",
////                                         "DIV ",
////                                         "PEEK myVar ",
////                                         "# PRINT (9 - myVar) * 20 ",
////                                         "POP ",
////                                         "PUSH 9 ",
////                                         "PUSH myVar ",
////                                         "MINUS ",
////                                         "PUSH 20 ",
////                                         "MUL ",
////                                         "PRINT"};
////    testing::internal::CaptureStdout();
////    command_processing(commands);
////
////    std::string expect_result("# myVar = -14 / 5 \n# PRINT (9 - myVar) * 20 \n220\n");
////
////    std::string stdout_result = testing::internal::GetCapturedStdout();
////
////    EXPECT_EQ(stdout_result, expect_result);
////}
////
////
////TEST(test2, test_2) {
////    std::vector<std::string> commands = {"PUSH -72",
////                                         "ABS",
////                                         "PUSH 4",
////                                         "DIV",
////                                         "PRINT"};
////    testing::internal::CaptureStdout();
////    command_processing(commands);
////
////    std::string expect_result("18\n");
////
////    std::string stdout_result = testing::internal::GetCapturedStdout();
////
////    EXPECT_EQ(stdout_result, expect_result);
////}
////
////
////
////
////TEST(test3, test_3) {
////    std::vector<std::string> commands = {"READ 234",
////                                         "PUSH 66",
////                                         "PLUS",
////                                         "PRINT"};
////    testing::internal::CaptureStdout();
////    command_processing(commands);
////
////    std::string expect_result("300\n");
////
////    std::string stdout_result = testing::internal::GetCapturedStdout();
////
////    EXPECT_EQ(stdout_result, expect_result);
////}
////
////TEST(test4, test_4) {
////    std::vector<std::string> commands = {"# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2",
////                                         "# (a + c) * d - e / (f - g) = 16",
////
////                                         "PUSH 4",
////                                         "PEEK a",
////                                         "POP",
////
////                                         "PUSH 6",
////                                         "PEEK c",
////                                         "POP ",
////
////                                         "PUSH 2",
////                                         "PEEK d",
////                                         "POP ",
////
////                                         "PUSH 36",
////                                         "PEEK e",
////                                         "POP",
////
////                                         "PUSH 11",
////                                         "PEEK f",
////                                         "POP",
////
////                                         "PUSH 2",
////                                         "PEEK g",
////                                         "POP",
////
////                                         "PUSH a",
////                                         "PUSH c",
////
////                                         "PLUS",
////
////                                         "PUSH d",
////
////                                         "MUL",
////
////                                         "PUSH e",
////
////                                         "PUSH g",
////
////                                         "MINUS",
////
////                                         "DIV",
////
////                                         "MINUS",
////
////                                         "PRINT"};
////    testing::internal::CaptureStdout();
////    command_processing(commands);
////
////    std::string expect_result("# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2\n"
////                              "# (a + c) * d - e / (f - g) = 16 \n"
////                              "16 \n");
////
////    std::string stdout_result = testing::internal::GetCapturedStdout();
////    std::cout << expect_result << std::endl;
////    std::cout << stdout_result << std::endl;
////    EXPECT_EQ(stdout_result, expect_result);
////}


TEST(test1, test_1) {
    std::vector<std::string> commands = {"# myVar = -14 / 5 ",
                                         "PUSH -14 ",
                                         "PUSH 5 ",
                                         "DIV ",
                                         "PEEK myVar ",
                                         "# PRINT (9 - myVar) * 20 ",
                                         "POP ",
                                         "PUSH 9 ",
                                         "PUSH myVar ",
                                         "MINUS ",
                                         "PUSH 20 ",
                                         "MUL ",
                                         "PRINT"};
    command_processing();

    std::string expect_result("# myVar = -14 / 5 \n# PRINT (9 - myVar) * 20 \n220\n");

    EXPECT_EQ(expect_result, std::cout);
}
//
//TEST(test1, test_1) {
//    std::vector<std::string> commands = {"# myVar = -14 / 5 ",
//                                         "PUSH -14 ",
//                                         "PUSH 5 ",
//                                         "DIV ",
//                                         "PEEK myVar ",
//                                         "# PRINT (9 - myVar) * 20 ",
//                                         "POP ",
//                                         "PUSH 9 ",
//                                         "PUSH myVar ",
//                                         "MINUS ",
//                                         "PUSH 20 ",
//                                         "MUL ",
//                                         "PRINT"};
//    testing::internal::CaptureStdout();
//    command_processing(commands);
//
//    std::string expect_result("# myVar = -14 / 5 \n# PRINT (9 - myVar) * 20 \n220\n");
//
//    std::string stdout_result = testing::internal::GetCapturedStdout();
//
//    EXPECT_EQ(stdout_result, expect_result);
//}
//
//
//TEST(test2, test_2) {
//    std::vector<std::string> commands = {"PUSH -72",
//                                         "ABS",
//                                         "PUSH 4",
//                                         "DIV",
//                                         "PRINT"};
//    testing::internal::CaptureStdout();
//    command_processing(commands);
//
//    std::string expect_result("18\n");
//
//    std::string stdout_result = testing::internal::GetCapturedStdout();
//
//    EXPECT_EQ(stdout_result, expect_result);
//}
//
//
//
//
//TEST(test3, test_3) {
//    std::vector<std::string> commands = {"READ 234",
//                                         "PUSH 66",
//                                         "PLUS",
//                                         "PRINT"};
//    testing::internal::CaptureStdout();
//    command_processing(commands);
//
//    std::string expect_result("300\n");
//
//    std::string stdout_result = testing::internal::GetCapturedStdout();
//
//    EXPECT_EQ(stdout_result, expect_result);
//}
//
//TEST(test4, test_4) {
//    std::vector<std::string> commands = {"# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2",
//                                         "# (a + c) * d - e / (f - g) = 16",
//
//                                         "PUSH 4",
//                                         "PEEK a",
//                                         "POP",
//
//                                         "PUSH 6",
//                                         "PEEK c",
//                                         "POP ",
//
//                                         "PUSH 2",
//                                         "PEEK d",
//                                         "POP ",
//
//                                         "PUSH 36",
//                                         "PEEK e",
//                                         "POP",
//
//                                         "PUSH 11",
//                                         "PEEK f",
//                                         "POP",
//
//                                         "PUSH 2",
//                                         "PEEK g",
//                                         "POP",
//
//                                         "PUSH a",
//                                         "PUSH c",
//
//                                         "PLUS",
//
//                                         "PUSH d",
//
//                                         "MUL",
//
//                                         "PUSH e",
//
//                                         "PUSH g",
//
//                                         "MINUS",
//
//                                         "DIV",
//
//                                         "MINUS",
//
//                                         "PRINT"};
//    testing::internal::CaptureStdout();
//    command_processing(commands);
//
//    std::string expect_result("# a = 4, c = 6, d = 2, e = 36, f = 11, g = 2\n"
//                              "# (a + c) * d - e / (f - g) = 16 \n"
//                              "16 \n");
//
//    std::string stdout_result = testing::internal::GetCapturedStdout();
//    std::cout << expect_result << std::endl;
//    std::cout << stdout_result << std::endl;
//    EXPECT_EQ(stdout_result, expect_result);
//}