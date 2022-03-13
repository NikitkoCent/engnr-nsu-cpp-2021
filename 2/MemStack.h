#pragma once

#include <stack>
#include <map>
#include <string>

#include "Errors.h"

class MemStack
{
private:
	map<string, int64_t> _var;
	stack<int64_t> _stk;
public:
	int64_t Pop();
	int64_t Pull();
	void Push(int64_t val);

	int64_t GetVar(std::string name);
	void SetVar(std::string name, int64_t val);
};
