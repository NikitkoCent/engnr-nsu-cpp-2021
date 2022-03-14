#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Operation.h"

class OperationHandler
{
private:
	std::map<std::string, std::shared_ptr<IOperation>> ops;
public:
	OperationHandler();
	std::shared_ptr<IOperation> Get(std::string command);
};
