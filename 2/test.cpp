//
// Created by gav on 08/10/2021.
//

#include "gtest/gtest.h"

#include "StackCalculator.hpp"

TEST(test, test_1){
    StackCalculator stackCalculator;
    stringstream ss("# myVar = -14 / 5\n"
                    "PUSH -14\n"
                    "PUSH 5\n"
                    "DIV\n"
                    "PEEK myVar\n"
                    "POP\n"
                    "# PRINT (9 - myVar) * 20\n"
                    "PUSH 9\n"
                    "PUSH myVar\n"
                    "MINUS\n"
                    "PUSH 20\n"
                    "MUL\n"
                    "PRINT");
    stackCalculator.parse_stream(ss);
    EXPECT_EQ(220, (int64_t)stackCalculator.get_ctx().get_map()["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"]);
}

TEST(test, test_2){
    StackCalculator stackCalculator;
    stringstream ss("# myVar = 90 \n"
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
                    "PRINT");
    stackCalculator.parse_stream(ss);
    EXPECT_EQ(2, (int64_t)stackCalculator.get_ctx().get_map()["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"]);
}


TEST(test, test_3){
    StackCalculator stackCalculator;
    stringstream ss("PUSH 4\n"
                    "PEEK a\n"
                    "POP\n"
                    "PUSH 6\n"
                    "PEEK c\n"
                    "POP\n"
                    "PUSH 2\n"
                    "PEEK d\n"
                    "POP\n"
                    "PUSH 36\n"
                    "PEEK e\n"
                    "POP\n"
                    "PUSH 11\n"
                    "PEEK f\n"
                    "POP\n"
                    "PUSH 2\n"
                    "PEEK g\n"
                    "POP\n"
                    "PUSH a\n"
                    "PUSH c\n"
                    "PLUS\n"
                    "PUSH d\n"
                    "MUL\n"
                    "PUSH e\n"
                    "PUSH f\n"
                    "PUSH g\n"
                    "MINUS\n"
                    "DIV\n"
                    "MINUS\n"
                    "PRINT");
    stackCalculator.parse_stream(ss);
    EXPECT_EQ(16, (int64_t)stackCalculator.get_ctx().get_map()["last_print_don_t_use_me_as_variable_name_pleeeeezzzzzzzzz"]);
}

TEST(test, test_4){
    StackCalculator stackCalculator;
    stringstream ss("# myVar = 90 \n"
                    "PUSH -9223372036854775808\n"
                    "ABS\n"
                    "PRINT");
//    stackCalculator.parse_stream(ss);
    EXPECT_THROW(stackCalculator.parse_stream(ss), OverflowException);
}



