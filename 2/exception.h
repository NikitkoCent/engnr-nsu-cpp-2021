#pragma once

#include <iostream>

class StackException : public std::exception {
public:
    std::string text = "ERROR: ";

    StackException() : std::exception() {
    };

    virtual std::string what() = 0;
};

class WrongArgument : public StackException {
public:
    std::string wrong;

    WrongArgument() : wrong("Wrong argument ") {
    };

    virtual std::string what() override;
};

class EmptyStack : public StackException {
public:
    std::string empty;

    EmptyStack() : empty("Empty stack error: ") {
    };

    std::string what() override;
};

class FewElementError : public StackException {
public:
    std::string few_elem;

    FewElementError() : few_elem("Too few elements in stack for operation:") {
    };

    virtual std::string what() override;
};

class PopException : public EmptyStack {
public:
    std::string pop;

    PopException() : pop("POP operation failed.") {
    };

    virtual std::string what() override;
};

class PushException : public WrongArgument {
public:
    std::string push;

    explicit PushException() : push("Variable doesn't exist. PUSH operation failed.") {
    };

    virtual std::string what() override;
};

class PeekException : public EmptyStack {
public:
    std::string peek;

    explicit PeekException() : peek("PEEK operation failed.") {
    };

    virtual std::string what() override;
};


class AbsException : public EmptyStack {
public:
    std::string abs;

    explicit AbsException() : abs("ABS operation failed.") {
    };

    virtual std::string what() override;
};


class PlusException : public FewElementError {
public:
    std::string plus;

    explicit PlusException() : plus("PLUS operation failed.") {
    };

    virtual std::string what() override;
};


class MinusException : public FewElementError {
public:
    std::string minus;

    explicit MinusException() : minus("MINUS operation failed.") {
    };

    virtual std::string what() override;
};


class MultiplyException : public FewElementError {
public:
    std::string mul;

    explicit MultiplyException() : mul("MUL operation failed.") {
    };

    virtual std::string what() override;
};


class DivisionException : public FewElementError {
public:
    std::string div;

    explicit DivisionException() : div("DIV operation failed.") {
    };

    virtual std::string what() override;
};

class PrintException : public EmptyStack {
public:
    std::string print;

    PrintException() : print("PRINT operation failed.") {
    };

    virtual std::string what() override;
};


