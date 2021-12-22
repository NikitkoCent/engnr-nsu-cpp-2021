#pragma once

#include <iostream>

class StackException : public std::exception {
protected:
    std::string text = " ERROR: ";
public:

    virtual std::string what() = 0;
};

class DivException : public StackException {
public:
    DivException() {
        text += " div exception ";
    }
    explicit DivException(std::string text_);

    std::string what() override {
        return text;
    }
};

class ZeroDivisionException : public DivException {
public:
    ZeroDivisionException() : DivException() {
        text += " zero division error ";
    }
    std::string what() {
        return text;
    }
};

class MulException : public StackException {
public:
    MulException() {
        text += " mul exception ";
    }
    MulException(std::string text_);
    std::string what() {
        return text;
    }
};

class PlusException : public StackException {
public:
    PlusException() {
        text += " plus exception ";
    }
    PlusException(std::string text_);
    std::string what() {
        return text;
    }
};

class MinusException : public StackException {
public:
    MinusException() {
        text += " minus exception ";
    }
    MinusException(std::string text_);
    std::string what() {
        return text;
    }
};

class PrintException : public StackException {
public:
    PrintException() {
        text += " print exception ";
    }
    PrintException(std::string text_);
    std::string what() {
        return text;
    }
};

class PrintEmptyStack : public PrintException {
public:
    PrintEmptyStack() : PrintException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};


class DivEmptyStack : public DivException {
public:
    DivEmptyStack() : DivException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class PlusEmptyStack : public PlusException {
public:
    PlusEmptyStack() : PlusException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class MinusEmptyStack : public MinusException {
public:
    MinusEmptyStack() : MinusException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class MulEmptyStack : public MulException {
public:
    MulEmptyStack() : MulException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class PushException : public StackException {
public:
    PushException() {
        text += " push exception ";
    }
    PushException(std::string text_);
    std::string what() {
        return text;
    }
};

class PushEmptyVarname : public PushException {
public:
    PushEmptyVarname() : PushException() {
        text += " empty varname ";
    }

    std::string what() {
        return text;
    }
};

class PushIntegerOverflow : public PushException {
public:
    PushIntegerOverflow() : PushException() {
        text += " integer overflow ";
    }

    std::string what() {
        return text;
    }
};

class PeekException : public StackException {
public:
    PeekException() {
        text += " peek exception ";
    }
    PeekException(std::string text_);
    std::string what() {
        return text;
    }
};

class PeekEmptyVarname : public PeekException {
public:
    PeekEmptyVarname() : PeekException() {
        text += " empty varname ";
    }

    std::string what() {
        return text;
    }
};

class PeekEmptyStack : public PeekException {
public:
    PeekEmptyStack() : PeekException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class AbsException : public StackException {
public:
    AbsException() {
        text += " abs exception ";
    }
    AbsException(std::string text_);
    std::string what() {
        return text;
    }
};

class AbsStackEmpty : public AbsException {
public:
    AbsStackEmpty() : AbsException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class PopException : public StackException {
public:
    PopException() {
        text += " pop exception ";
    }
    PopException(std::string text_);
    std::string what() {
        return text;
    }
};

class PopStackEmpty : public PopException {
public:
    PopStackEmpty() : PopException() {
        text += " empty stack ";
    }

    std::string what() {
        return text;
    }
};

class CommandException : public StackException {
public:
    CommandException() {
        text += " command exception ";
    }
    CommandException(std::string text_);
    std::string what() {
        return text;
    }
};
