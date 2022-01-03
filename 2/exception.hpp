

class default_error: public std::exception{
public:
    std::string text;
    virtual std::string what() = 0;
};
class mulexc : public default_error {
public:
    mulexc(){
        text = "ERROR: MUL_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class divexc: public default_error {
public:
    divexc(){
        text = "ERROR: DIV_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class plusexc: public default_error {
public:
    plusexc(){
        text = "ERROR: PLUS_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class minusexc: public default_error {
public:
    minusexc(){
        text = "ERROR: MINUS_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class popexc: public default_error {
public:
    popexc(){
        text = "ERROR: POP_empty_stack";
    }
    std::string  what() override {
        return text;
    }
};
class pushexc: public default_error {
public:
    pushexc(){
        text = "ERROR: PUSH_fatal_error";
    }
    std::string what() override {
        return text;
    }
};
class DivideByZero: public default_error {
public:
    DivideByZero(){
        text = "ERROR: Divide by zero";
    }
    std::string what() override {
        return text;
    }
};
class printexc: public default_error {
public:
    printexc(){
        text = "ERROR: PRINT_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class peekexc: public default_error {
public:
    peekexc(){
        text = "ERROR: PEEK_empty_stack";
    }
    std::string what() override {
        return text;
    }
};
class absexc: public default_error {
public:
    absexc(){
        text = "ERROR: ABS_empty_stack or something wrong";
    }
    std::string what() override {
        return text;
    }
};
class readexc: public default_error {
public:
    readexc(){
        text = "ERROR: READ_fatal_error";
    }
    std::string what() override {
        return text;
    }
};
class commandexc: public default_error {
public:
    commandexc(){
        text = "ERROR: this command doesn't exist";
    }
    std::string what() override {
        return text;
    }
};
class noargsexc: public default_error {
public:
    noargsexc(){
        text = "ERROR: args less then 2";
    }
    std::string what() override {
        return text;
    }
};
class manyargsexc: public default_error {
public:
    manyargsexc(){
        text = "ERROR: too many args";
    }
    std::string what() override {
        return text;
    }
};