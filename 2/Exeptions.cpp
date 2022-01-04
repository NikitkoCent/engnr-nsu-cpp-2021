#define INC_2_EXEPTIONS_H

#include <iostream>
#include <string>
#include "Exeptions.h"


std::string CalcExceptions::PushException::_what() {
    return base_error + push_error;
}
std::string CalcExceptions::EmptyVarName::_what() {
    return base_error + push_error + fir_push_error;
}
std::string CalcExceptions::InvalidInput::_what() {
    return base_error + push_error + sec_push_error;
}

std::string CalcExceptions::PopException::_what() {
    return base_error + pop_error;
}
std::string CalcExceptions::Empty::_what() {
    return base_error + pop_error + empty_pop;
}


std::string CalcExceptions::ReadException::_what() {
    return base_error + read_error;
}
std::string CalcExceptions::EmptyName::_what() {
    return base_error + read_error + name_error;
}



std::string CalcExceptions::StackEx::_what() {
    return base_error + stack_error;
}
std::string CalcExceptions::StackDeficit::_what() {
    return base_error + stack_error + Def_error;
}
std::string CalcExceptions::StackEmpty::_what() {
    return base_error + stack_error + empty_error;
}

std::string CalcExceptions::DivisionByZero::_what() {
    return base_error + zero_error;
}

std::string CalcExceptions::InvalidOperation::_what() {
    return base_error + operation_error;
}
