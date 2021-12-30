

class default_error: std::exception{
public:
    std::string text;
};
class mulexc : public default_error {
public:
    mulexc(){
        text = "ERROR: MUL_empty_stack or 1 elem";
    }
};
class divexc: public default_error {
public:
    divexc(){
        text = "ERROR: DIV_empty_stack or 1 elem";
    }
};
class plusexc: public default_error {
public:
    plusexc(){
        text = "ERROR: PLUS_empty_stack or 1 elem";
    }
};
class minusexc: public default_error {
public:
    minusexc(){
        text = "ERROR: MINUS_empty_stack or 1 elem";
    }
};
class popexc: public default_error {
public:
    popexc(){
        text = "ERROR: POP_empty_stack";
    }
};
class pushexc: public default_error {
public:
    pushexc(){
        text = "ERROR: PUSH_fatal_error";
    }
};
class DivideByZero: public default_error {
public:
    DivideByZero(){
        text = "ERROR: Divide by zero";
    }
};
class printexc: public default_error {
public:
    printexc(){
        text = "ERROR: PRINT_empty_stack";
    }
};
class peekexc: public default_error {
public:
    peekexc(){
        text = "ERROR: PEEK_empty_stack";
    }
};
class absexc: public default_error {
public:
    absexc(){
        text = "ERROR: ABS_empty_stack or something wrong";
    }
};
class readexc: public default_error {
public:
    readexc(){
        text = "ERROR: READ_fatal_error";
    }
};
class commandexc: public default_error {
public:
    commandexc(){
        text = "ERROR: this command doesn't exist";
    }
};