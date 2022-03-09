#pragma once

#include <map>
#include <stack>
#include <string>

#include "MError.h"

class Memory
{
private:
	std::stack<int64_t> stack;
	std::map<std::string, int64_t> variables;
public:
	void Push(int64_t val);
	int64_t Pop();
	int64_t Pull();

	void Set(std::string name, int64_t val);
	int64_t Get(std::string name);
	void Remove(std::string name);
};
