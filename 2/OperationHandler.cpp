#include "OperationHandler.h"

OperationHandler::OperationHandler()
{
	std::vector<std::shared_ptr<IOperation>> opList =
	{
		std::make_shared<Pop>(),
		std::make_shared<Push>(),
		std::make_shared<Peek>(),
		std::make_shared<Abs>(),
		std::make_shared<Plus>(),
		std::make_shared<Minus>(),
		std::make_shared<Mul>(),
		std::make_shared<Div>(),
		std::make_shared<Print>(),
		std::make_shared<Read>(),
		std::make_shared<Comment>(),
	};

	for (size_t i = 0; i < opList.size(); i++)
		ops[opList[i].get()->Name()] = opList[i];
}

std::shared_ptr<IOperation> OperationHandler::Get(std::string command)
{
	if (ops.find(command) == ops.end())
		throw UnknownCommand(command);
	return ops[command];
}