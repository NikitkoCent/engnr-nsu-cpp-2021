#include "MemStack.h"

void CheckVarName(std::string& name)
{
	if (name.empty() || !std::all_of(std::execution::seq, name.begin(), name.end(), std::isalpha))
		throw VarName();
}


int64_t MemStack::Pop()
{
	auto res = Pull();
	_stk.pop();
	return res;
}

int64_t MemStack::Pull()
{
	if (_stk.empty())
		throw Empty();
	return _stk.top();
}

void MemStack::Push(int64_t val)
{
	_stk.push(val);
}

int64_t MemStack::GetVar(std::string name)
{
	CheckVarName(name);
	auto var = _var.find(name);
	if (var == _var.end())
		throw UVar();
	return var->second;
}

void MemStack::SetVar(std::string name, int64_t val)
{
	CheckVarName(name);
	_var[name] = val;
}
