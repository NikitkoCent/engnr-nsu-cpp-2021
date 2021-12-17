//
// Created by Mikhail Okan on 15.12.2021.
//

#include "Excpetions.h"

std::string StackExceptions::InvalidArgument::_what() {
    return default_error + invalid_error;
}

std::string StackExceptions::PushException::_what() {
    return default_error + invalid_error + push_error;
}

std::string StackExceptions::StackEmpty::_what() {
    return default_error + empty_error;
}

std::string StackExceptions::ReadException::_what() {
    return default_error + read_error;
}

std::string StackExceptions::StackLack::_what() {
    return default_error + lack_error;
}

//std::string StackExceptions::OverflowException::_what() {
//    return default_error + overflow_error;
//}

std::string StackExceptions::DivisionByZero::_what() {
    return default_error + zero_error;
}

std::string StackExceptions::InvalidOperation::_what() {
    return default_error + operation_error;
}