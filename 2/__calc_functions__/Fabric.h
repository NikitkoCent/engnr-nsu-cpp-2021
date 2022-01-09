#include "Lab_2.h"

class Operations {
public:
    virtual void execute(Param& p) = 0;
    virtual ~Operations() {}
};

class pop_cmd : public Operations {
public:
    void execute(Param& p);
    //void Operations(Param& p);
};

class push_cmd : public Operations {
public:
    void execute(Param& p);
};

class peek_cmd : public Operations {
public:
    void execute(Param& p);
};

class abs_cmd : public Operations {
public:
    void execute(Param& p);
};

class plus_cmd : public Operations {
public:
    void execute(Param& p);
};

class  mul_cmd : public Operations {
public:
    void execute(Param& p);
};

class  minus_cmd : public Operations {
public:
    void execute(Param& p);
};

class  div_cmd : public Operations {
public:
    void execute(Param& p);
};

class  print_cmd : public Operations {
public:
    void execute(Param& p);
};

class  read_cmd : public Operations {
public:
    void execute(Param& p);
};

#pragma once
