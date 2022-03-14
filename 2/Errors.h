#pragma once

#include <string>

class Errors
{
private:
	std::string _text;
public:
	Errors(std::string text) : _text(text) {}
	std::string Text() { return _text; }
	virtual ~Errors() = default;
};

class Overflow : public Errors
{
public:
	Overflow() : Errors("overflow") {}
};

class Empty : public Errors
{
public:
	Empty() : Errors("stack empty") {}
};

class UVar : public Errors
{
public:
	UVar() : Errors("unknown variable") {}
};

class UCommand : public Errors
{
public:
	UCommand() : Errors("unknown command") {}
};

class VarName : public Errors
{
public:
	VarName() : Errors("invalid variable name") {}
};

class FloodedCommand : public Errors
{
public:
	FloodedCommand() : Errors("unexpected argument") {}
};

class NotANumber : public Errors
{
public:
	NotANumber() : Errors("int number expected") {}
};
