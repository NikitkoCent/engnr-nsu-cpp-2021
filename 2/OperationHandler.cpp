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

	for (auto i = opList.begin(); i != opList.end(); i++)
		ops[(*i).get()->Name()] = *i;
}

std::shared_ptr<IOperation> OperationHandler::Get(std::string command)
{
	auto op = ops.find(command);
	if (op == ops.end())
		throw UnknownCommand(command);
	return op->second;
}
