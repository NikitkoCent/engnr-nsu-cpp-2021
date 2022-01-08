#include "T_Lab_2.h"
#include "T_Fabric.h"

class Factory {
public:
    virtual Operations* Create(Param s) = 0;
    virtual ~Factory() {}
};

class OperationsFactory : public Factory {
public:
    Operations* Create(Param s);
    
};
