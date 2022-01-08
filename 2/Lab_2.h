#pragma once
#include "./SafeInt/SafeInt.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::stack;
using std::vector;
using std::map;
using std::ifstream;
using std::stringstream;
using std::invalid_argument;
using std::endl;

class Exception : public std::exception
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



class Param {
public:
    stack<SafeInt<int64_t, IntOverflow>> stk;
    vector<string> vst;
    map<string, SafeInt<int64_t, IntOverflow>> var;

    ~Param() {
        vst.clear();
        stk = stack<SafeInt<int64_t, IntOverflow>>();
        var.clear();
    }
};
void split(Param &p, const std::string& s, char delim);
bool strToInteger(Param p);
bool check(Param s);
