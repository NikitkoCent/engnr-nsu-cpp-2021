//
// Created by Mikhail Okan on 10.12.2021.
//

#include "googletest/googletest/include/gtest/gtest.h"
#include "StackCalc.h"
#include <iostream>
TEST (sc, test_1) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "PRINT\n";


    std::string result = "3\n";
    std::stringstream in(test);

    testing::internal::CaptureStdout();
    calc.execute(in);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(result, output);
}

TEST (sc, test_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 125\n"
                       "PUSH 25\n"
                       "MUL\n"
                       "PUSH 7\n"
                       "DIV\n"
                       "PEEK myVar\n"
                       "PUSH 4\n"
                       "MUL\n"
                       "PUSH myVar\n"
                       "DIV\n"
                       "PUSH -1\n"
                       "MUL\n"
                       "ABS\n"
                       "PRINT";
    std::string result = "4\n";
    std::stringstream in(test);
    testing::internal::CaptureStdout();
    calc.execute(in);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, output);
}

TEST (sc, test_3) {
    SC::StackCalc calc;
    std::string test = "# myVar = -14 / 5\n"
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
                       "PRINT";
    std::string result = "220\n";
    std::stringstream in(test);
    testing::internal::CaptureStdout();
    calc.execute(in);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, output);
}

TEST (sc, test_4) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "PUSH 5\n"
                       "MUL\n"
                       "PRINT";
    std::string result = "15\n";
    std::stringstream in(test);
    testing::internal::CaptureStdout();
    calc.execute(in);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, output);
}

TEST (sc, test_spaces) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "\n"
                       "PUSH 2\n"
                       "PLUS\n"
                       "\n"
                       "PUSH 5\n"
                       "\n"
                       "MUL\n"
                       "PRINT";
    std::string result = "15\n";
    std::stringstream in(test);
    testing::internal::CaptureStdout();
    calc.execute(in);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, output);
}

TEST (sc, pop_exception) {
    SC::StackCalc calc;
    std::string test = "POP\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackEmpty &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack is empty!"));
    }
}

TEST (sc, print_exception) {
    SC::StackCalc calc;
    std::string test = "PRINT\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackEmpty &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack is empty!"));
    }
}

TEST (sc, peek_exception) {
    SC::StackCalc calc;
    std::string test = "PEEK\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackEmpty &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack is empty!"));
    }
}


TEST (sc, wrong_push_exception) {
    SC::StackCalc calc;
    std::string test = "PUSH a\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::InvalidArgument &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Invalid argument in method PUSH (arg is not an integer or variable)!"));
    }
}

TEST (sc, wrong_push_exception_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 1-2\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::InvalidArgument &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Invalid argument in method PUSH (arg is not an integer or variable)!"));
    }
}

TEST (sc, wrong_operation) {
    SC::StackCalc calc;
    std::string test = "PUSH 5\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::InvalidArgument &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Invalid operation!"));
    }
}

TEST (sc, plus_exception) {
    SC::StackCalc calc;
    std::string test = "PLUS\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, plus_exception_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PLUS\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}


TEST (sc, minus_exception) {
    SC::StackCalc calc;
    std::string test = "MINUS\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, minus_exception_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "MINUS\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, mul_exception) {
    SC::StackCalc calc;
    std::string test = "MUL\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, mul_exception_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "MUL\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, div_exception) {
    SC::StackCalc calc;
    std::string test = "DIV\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}

TEST (sc, div_exception_2) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "DIV\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::StackLack &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Stack has less than 2 arguments!"));
    }
}


TEST (sc, zero_division_exception) {
    SC::StackCalc calc;
    std::string test = "PUSH 1\n"
                       "PUSH 0\n"
                       "DIV\n";
    std::stringstream in(test);
    try {
        calc.execute(in);
    } catch (StackExceptions::DivisionByZero &err) {
        EXPECT_EQ(err._what(), std::string("\nStackCalc Exception: Division by zero!"));
    }
}
