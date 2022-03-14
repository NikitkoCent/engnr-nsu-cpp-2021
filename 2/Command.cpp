#include "Command.h"

bool SafeIntFromStr(std::string& str, int64_t& result)
{
	auto [ptr, ec] { std::from_chars(str.data(), str.data() + str.size(), result) };

	if (ec == std::errc())
	{
		if (!(std::stringstream(ptr) >> std::ws).eof())
			return false;
		return true;
	}
	else if (ec == std::errc::result_out_of_range)
		throw Overflow();
	return false;
}

void Pop::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	_memory.Pop();
}

void Push::Work(std::string args)
{
	std::stringstream st(args);
	std::string arg;
	st >> arg;
	if (!(st >> std::ws).eof())
		throw FloodedCommand();
	int64_t val;
	if (SafeIntFromStr(arg, val))
		_memory.Push(val);
	else
		_memory.Push(_memory.GetVar(arg));
}

void Peek::Work(std::string args)
{
	std::stringstream st(args);
	std::string arg;
	st >> arg;
	if (!(st >> std::ws).eof())
		throw FloodedCommand();
	_memory.SetVar(arg, _memory.Pull());
}

void Abs::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	auto val = _memory.Pop();
	if (val < 0)
		if (!SafeMultiply(val, -1, val))
			throw Overflow();
	_memory.Push(val);
}

void Plus::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	int64_t res;
	if (!SafeAdd(_memory.Pop(), _memory.Pop(), res))
		throw Overflow();
	_memory.Push(res);
}

void Minus::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	auto x = _memory.Pop();
	auto y = _memory.Pop();
	int64_t res;
	if (!SafeSubtract(y, x, res))
		throw Overflow();
	_memory.Push(res);
}

void Mul::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	int64_t res;
	if (!SafeMultiply(_memory.Pop(), _memory.Pop(), res))
		throw Overflow();
	_memory.Push(res);
}

void Div::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	auto x = _memory.Pop();
	auto y = _memory.Pop();
	int64_t res;
	if (!SafeDivide(y, x, res))
		throw Overflow();
	_memory.Push(res);
}

void Print::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();

	std::cout << _memory.Pull() << std::endl;
}

void Read::Work(std::string args)
{
	if (!(std::stringstream(args) >> std::ws).eof())
		throw FloodedCommand();
	std::string arg;
	int64_t val;
	std::cin >> arg;
	if (SafeIntFromStr(arg, val))
		_memory.Push(val);
	else
		throw NotANumber();
}
