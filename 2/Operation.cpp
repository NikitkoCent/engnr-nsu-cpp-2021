#include "Operation.h"

bool CheckForReadingOverflow(int64_t val)
{
	return (val == std::numeric_limits<int64_t>::max()) || (val == std::numeric_limits<int64_t>::min());
}

void Pop::Use(Memory& mem, std::string args)
{
	mem.Pop();
}

void FPushVar(Memory& mem, std::string args)
{
	std::stringstream ss(args);
	std::string name;
	ss >> name;
	mem.Push(mem.Get(name));
}

void FPush(Memory& mem, std::string args)
{
	std::stringstream ss(args);
	int64_t val;
	if (ss >> val)
	{
		mem.Push(val);
		return;
	}

	if (CheckForReadingOverflow(val))
		throw Overflow();
	else
		throw NotANumber();
}

void Push::Use(Memory& mem, std::string args)
{
	try
	{
		return FPush(mem, args);
	}
	catch (NotANumber& err)
	{
		return FPushVar(mem, args);
	}
}

void Peek::Use(Memory& mem, std::string args)
{
	std::stringstream ss(args);
	std::string name;
	ss >> name;
	mem.Set(name, mem.Pull());
}

void Abs::Use(Memory& mem, std::string args)
{
	auto val = mem.Pop();
	if (val < 0)
		if (!SafeMultiply(val, -1, val))
			throw Overflow();
	mem.Push(val);
}

void Plus::Use(Memory& mem, std::string args)
{
	int64_t res;
	if (!SafeAdd(mem.Pop(), mem.Pop(), res))
		throw Overflow();
	mem.Push(res);
}

void Minus::Use(Memory& mem, std::string args)
{
	auto x = mem.Pop();
	auto y = mem.Pop();
	int64_t res;
	if (!SafeSubtract(y, x, res))
		throw Overflow();
	mem.Push(res);
}

void Mul::Use(Memory& mem, std::string args)
{
	int64_t res;
	if (!SafeMultiply(mem.Pop(), mem.Pop(), res))
		throw Overflow();
	mem.Push(res);
}

void Div::Use(Memory& mem, std::string args)
{
	auto x = mem.Pop();
	auto y = mem.Pop();
	int64_t res;
	if (!SafeDivide(y, x, res))
		throw Overflow();
	mem.Push(res);
}

void Print::Use(Memory& mem, std::string args)
{
	std::string res = std::to_string(mem.Pull());
	std::cout << args << res << std::endl;
}

void Read::Use(Memory& mem, std::string args)
{
	std::cout << args;
	std::string arg;
	std::cin >> arg;
	return FPush(mem, arg);
}
