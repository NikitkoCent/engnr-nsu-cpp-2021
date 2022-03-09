#include "Memory.h"

void Memory::Push(int64_t val)
{
	stack.push(val);
}

int64_t Memory::Pop()
{
	auto res = Pull();
	stack.pop();
	return res;
}

int64_t Memory::Pull()
{
	if (stack.empty())
		throw EmptyStack();
	return stack.top();
}

void Memory::Set(std::string name, int64_t val)
{
	variables[name] = val;
}

int64_t Memory::Get(std::string name)
{
	if (variables.find(name) == variables.end())
		throw UnknownVariable(name);
	return variables[name];
}

void Memory::Remove(std::string name)
{
	variables.erase(name);
}