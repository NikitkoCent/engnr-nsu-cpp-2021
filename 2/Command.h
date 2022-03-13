#pragma once

#include <string>
#include <sstream>
#include <climits>
#include <iostream>

#include "MemStack.h"
#include "Errors.h"
#include "libs/SafeInt/SafeInt.hpp"

class Command
{
protected:
	MemStack& _memory;
public:
	Command(MemStack& memory) : _memory(memory) {}
	virtual void Work(std::string args) = 0;
};

class Pop : public Command
{
public:
	Pop(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Push : public Command
{
public:
	Push(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Peek : public Command
{
public:
	Peek(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Abs : public Command
{
public:
	Abs(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Plus : public Command
{
public:
	Plus(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Minus : public Command
{
public:
	Minus(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Mul : public Command
{
public:
	Mul(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Div : public Command
{
public:
	Div(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Print : public Command
{
public:
	Print(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Read : public Command
{
public:
	Read(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override;
};

class Comment : public Command
{
public:
	Comment(MemStack& memory) : Command(memory) {}
	void Work(std::string args) override {}
};
