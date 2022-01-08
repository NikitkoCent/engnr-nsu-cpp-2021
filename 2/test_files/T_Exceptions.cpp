#include "T_Lab_2.h"
//#include "Exceptions.h"

const string EmptyStack::GetError()
{
    return "Error: Empty Stack";
}


const string VarNotFound::GetError()
{
    return "Error: Variable Not Found";
}

const string OneArgumentStack::GetError()
{
    return "Error: Only 1 argument in the stack";
}

const string divByZero::GetError()
{
    return "Error: Division by 0";
}

const string ArgNotEntered::GetError()
{
    return "Argument was not entered";
}

const string NoCommand::GetError()
{
    return "Command not found";
}

const string SafeIntExceptionStack::GetError()
{
    return "SafeIngter number overflow";
}

void IntOverflow::SafeIntOnOverflow() {
    throw SafeIntExceptionStack();
}



