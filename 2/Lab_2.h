// Lab_2.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;
void split(vector<string>& result, const string& s, char delim);
bool strToInteger(const string& s);
void stack_case(const vector<string>& s, stack<double>& str, map<string, double>& mp);
// TODO: Reference additional headers your program requires here.
