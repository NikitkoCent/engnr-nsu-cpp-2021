#include "Memory.h"

void CheckVarName(std::string name)
{
	if (name.empty())
		throw InvalidVariableName(name);
	for (auto i = name.begin(); i != name.end(); i++)
		if (!std::isalpha(*i))
			throw InvalidVariableName(name);
}

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
	CheckVarName(name);
	variables[name] = val;
}

int64_t Memory::Get(std::string name)
{
	CheckVarName(name);
	auto var = variables.find(name);
	if (var == variables.end())
		throw UnknownVariable(name);
	return var->second;
}

void Memory::Remove(std::string name)
{
	CheckVarName(name);
	variables.erase(name);
}
