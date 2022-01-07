#include "gtest/gtest.h"
#include "Lab_2.h" 
//#include "Lab_2.cpp"
#include <sstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::stack;
using std::vector;
using std::map;
using std::ifstream;



TEST(TestCalc, Test1) {
	std::stringstream line_cmd("# (10 + 5*36)/4 + 15 PRINT\nPUSH 10 \nPUSH 5 \nPUSH 36 \nMUL \nSUM \nPUSH 4 \nDIV \nPUSH 15 \nSUM \nPRINT \n");
	Param p;
	string line;
	OperationsFactory create_stack;
	Operations* cmd_stack;
	int64_t result = 62;
	while (getline(line_cmd, line, '\n'))
	{
		split(p, line, ' ');
		if (p.vst.size() >= 1)
		{

		if (check(p)) {
					cmd_stack = create_stack.Create(p);
					cmd_stack->execute(p);
				}
				p.vst.clear();
			
		}
	}
	EXPECT_EQ(p.stk.top(), result);
}


TEST(TestCalc, Test_example) {
	string filename("tests/test_example/test.txt");
	Param p;
	string line;
	OperationsFactory create_stack;
	Operations* cmd_stack;
	int64_t result = 220;
	ifstream in(filename);
	while (getline(in, line))
	{
		split(p, line, ' ');
		if (p.vst.size() >= 1)
		{
			if (check(p)) {
				cmd_stack = create_stack.Create(p);
				cmd_stack->execute(p);
			}
			p.vst.clear();

		}
	}
	EXPECT_EQ(p.stk.top(), result);
}

TEST(TestCalc, Test_divByZero) {
	std::stringstream line_cmd("# (10 + 5*36)/0 PRINT"
		"PUSH 10 \n"
		"PUSH 5 \n"
		"PUSH 36 \n"
		"MUL \n"
		"SUM \n"
		"PUSH 0 \n"
		"DIV \n"
		"PUSH 15 \n"
		"SUM \n"
		"PRINT \n");
	string filename("tests/test_example/test.txt");
	Param p;
	string line;
	OperationsFactory create_stack;
	Operations* cmd_stack;
	ifstream in(filename);
	while (getline(line_cmd, line, '\n'))
	{
		split(p, line, ' ');
		if (p.vst.size() >= 1)
		{

			try {
				if (check(p)) {
					cmd_stack = create_stack.Create(p);
					cmd_stack->execute(p);
				}
				p.vst.clear();
			}
			catch (Exception& expn) {
				std::cerr << expn.what();
				EXPECT_EQ(expn.what(), string("Error: Division by 0"));

			}
		}
	}
}



TEST(TestCalc, Test_empty_stack) {
	std::stringstream line_cmd("# PUSH 5 POP POP"
		"PUSH 5 \n"
		"POP \n"
		"POP \n");
	Param p;
	string line;
	OperationsFactory create_stack;
	Operations* cmd_stack;
	while (getline(line_cmd, line, '\n'))
	{
		split(p, line, ' ');
		if (p.vst.size() >= 1)
		{

			try {
				if (check(p)) {
					cmd_stack = create_stack.Create(p);
					cmd_stack->execute(p);
				}
				p.vst.clear();
			}
			catch (Exception& expn) {
				std::cerr << expn.what();
				EXPECT_EQ(expn.what(), string("Error: Empty Stack"));

			}
		}
	}
}