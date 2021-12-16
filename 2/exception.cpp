#include "exception.h"

AbsException::AbsException(std::string text_) {
    text = text_;
}

PrintException::PrintException(std::string text_) {
    text = text_;
}

DivException::DivException(std::string text_) {
    text = text_;
}

MulException::MulException(std::string text_) {
    text = text_;
}

PlusException::PlusException(std::string text_) {
    text = text_;
}

MinusException::MinusException(std::string text_) {
    text = text_;
}

PushException::PushException(std::string text_) {
    text = text_;
}

PeekException::PeekException(std::string text_) {
    text = text_;
}


PopException::PopException(std::string text_) {
    text = text_;
}

CommandException::CommandException(std::string text_) {
    text = text_;
}
