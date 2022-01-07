#include "Lab_2.h"
#include "Exceptions.h"

const string EmptyStack::GetError()
    {
        return "Error: Empty Stack";
    }


const string VarNotFound::GetError()
{
    return "Error: Empty Stack";
}

const string OneArgumentStack::GetError()
{
    return "Error: Empty Stack";
}

const string divByZero::GetError()
{
    return "Error: Empty Stack";
}

const string ArgNotEntered::GetError()
{
    return "Error: Empty Stack";
}

const string NoCommand::GetError()
{
    return "Error: Empty Stack";
}

const string SafeIntExceptionStack::GetError()
{
    return "Error: Empty Stack";
}

void IntOverflow::SafeIntOnOverflow() {
    throw SafeIntExceptionStack();
}



