#pragma once

#include <string>

class MError
{
private:
	std::string errorText;
public:
	MError(std::string errorText) { this->errorText = errorText; }
	std::string ErrorText() { return errorText; }
	virtual ~MError() {}
};

class EmptyStack : public MError
{
public:
	EmptyStack() : MError("stack was empty") {}
};

class UnknownVariable : public MError
{
public:
	UnknownVariable(std::string varName) : MError("unknown variable: \"" + varName + "\"") {}
};

class InvalidVariableName : public MError
{
public:
	InvalidVariableName(std::string name) : MError("invalid variable name: \"" + name + "\"") {}
};

class Overflow : public MError
{
public:
	Overflow() : MError ("overflow") {}
};

class NotANumber : public MError
{
public:
	NotANumber() : MError("not a number") {}
};

class UnknownCommand : public MError
{
public:
	UnknownCommand(std::string command) : MError("unknown command: \"" + command + "\"") {}
};

class FileError : public MError
{
public:
	FileError(std::string path) : MError("couldn open file: \"" + path + "\"") {}
};

class UnexpectedError : public MError
{
public:
	UnexpectedError() : MError("unexpected error") {}
};
