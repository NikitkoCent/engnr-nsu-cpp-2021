#include "Lab_2.h"

class Exception: public std::exception
{
public:
    virtual const string GetError() = 0;
};


class EmptyStack : public Exception
{
public:
    virtual const string GetError();
};

class VarNotFound : public Exception
{
public:
    virtual const string GetError();
};

class OneArgumentStack : public Exception
{
public:
    virtual const string GetError();
};

class divByZero : public Exception
{
public:
    virtual const string GetError();
};

class ArgNotEntered : public Exception
{
public:
    virtual const string GetError();
};

class NoCommand : public Exception
{
public:
    virtual const string GetError();
};

class SafeIntExceptionStack : public Exception
{
public:
    virtual const string GetError();
};

class IntOverflow : public SafeIntException
{
public:
    static void SafeIntOnOverflow();
};


