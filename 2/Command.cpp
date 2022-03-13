#include "Command.h"

void CheckReadOverflow(int64_t val)
{
	if ((val == std::numeric_limits<int64_t>::max()) || (val == std::numeric_limits<int64_t>::min()))
		throw Overflow();
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
	st = std::stringstream(arg);
	int64_t val;
	if (st >> val)
	{
		CheckReadOverflow(val);
		_memory.Push(val);
	}
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
	_memory.SetVar(arg, _memory.Pop());
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
	int64_t val;
	if (std::cin >> val)
	{
		CheckReadOverflow(val);
		_memory.Push(val);
	}
	else
		throw NotANumber();
}