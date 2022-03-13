#pragma once

#include <string>

using namespace std;

class Errors
{
private:
	string _text;
public:
	Errors(string text) : _text(text) {}
	string Text() { return _text; }
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

class UCommand : public Errors
{
public:
	UCommand() : Errors("unknown command") {}
};