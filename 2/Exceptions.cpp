#include "Lab_2.h"

class Exception: public std::exception
{
public:
    virtual const string GetError() = 0;
};


class EmptyStack : public Exception
{
public:
    virtual const string GetError()
    {
        return "Error: Empty Stack";
    }
};

class VarNotFound : public Exception
{
public:
    virtual const string GetError()
    {
        return "Error: Variable Not Found"; 
    }
};

class OneArgumentStack : public Exception
{
public:
    virtual const string GetError()
    {
        return "Error: Only 1 argument in the stack";
    }
};

class divByZero : public Exception
{
public:
    virtual const string GetError()
    {
        return "Error: Division by 0";
    }
};

class ArgNotEntered : public Exception
{
public:
    virtual const string GetError()
    {
        return "Argument was not entered";
    }
};

class NoCommand : public Exception
{
public:
    virtual const string GetError()
    {
        return "Command not found";
    }
};
