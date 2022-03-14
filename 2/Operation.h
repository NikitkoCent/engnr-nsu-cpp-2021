#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <functional>

#include "Memory.h"
#include "SafeInt.hpp"
#include "MError.h"

class IOperation
{
private:
	std::string name;
public:
	IOperation(std::string name) { this->name = name; }
	std::string Name() { return name; };
	virtual void Use(Memory& mem, std::string args) = 0;
	virtual ~IOperation() {}
};

class Pop : public IOperation
{
public:
	Pop() : IOperation("POP") {}
	void Use(Memory& mem, std::string args) override;
};

class Push : public IOperation
{
public:
	Push() : IOperation("PUSH") {}
	void Use(Memory& mem, std::string args) override;
};

class Peek : public IOperation
{
public:
	Peek() : IOperation("PEEK") {}
	void Use(Memory& mem, std::string args) override;
};

class Abs : public IOperation
{
public:
	Abs() : IOperation("ABS") {}
	void Use(Memory& mem, std::string args) override;
};

class Plus : public IOperation
{
public:
	Plus() : IOperation("PLUS") {}
	void Use(Memory& mem, std::string args) override;
};

class Minus : public IOperation
{
public:
	Minus() : IOperation("MINUS") {}
	void Use(Memory& mem, std::string args) override;
};

class Mul : public IOperation
{
public:
	Mul() : IOperation("MUL") {}
	void Use(Memory& mem, std::string args) override;
};

class Div : public IOperation
{
public:
	Div() : IOperation("DIV") {}
	void Use(Memory& mem, std::string args) override;
};

class Print : public IOperation
{
public:
	Print() : IOperation("PRINT") {}
	void Use(Memory& mem, std::string args) override;
};

class Read : public IOperation
{
public:
	Read() : IOperation("READ") {}
	void Use(Memory& mem, std::string args) override;
};

class Comment : public IOperation
{
public:
	Comment() : IOperation ("#") {}
	void Use(Memory& mem, std::string args) override {};
};
