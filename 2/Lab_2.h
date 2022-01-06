#pragma once
#include "./SafeInt/SafeInt.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::stack;
using std::vector;
using std::map;
using std::ifstream;
using std::stringstream;
using std::invalid_argument;
using std::endl;
struct Param {
	stack<int64_t> stk;
	vector<string> vst;
	map<string, int64_t> var;

	~Param() {
		vst.clear();
		stk = stack<int64_t>();
		var.clear();
	}
};
void split(Param &p, const std::string& s, char delim);
bool strToInteger(Param p);
bool check(Param s);
