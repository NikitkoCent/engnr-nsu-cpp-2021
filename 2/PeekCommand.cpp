#include "PeekCommand.h"

PeekCommand::PeekCommand(MemStack& memory)
{
	_commands = std::map<std::string, std::shared_ptr<Command>>
	{
		{"POP", std::make_shared<Pop>(memory)},
		{"PUSH", std::make_shared<Push>(memory)},
		{"PEEK", std::make_shared<Peek>(memory)},
		{"ABS", std::make_shared<Abs>(memory)},
		{"PLUS", std::make_shared<Plus>(memory)},
		{"MINUS", std::make_shared<Minus>(memory)},
		{"MUL", std::make_shared<Mul>(memory)},
		{"DIV", std::make_shared<Div>(memory)},
		{"PRINT", std::make_shared<Print>(memory)},
		{"READ", std::make_shared<Read>(memory)},
		{"#", std::make_shared<Comment>(memory)},
	};
}

std::shared_ptr<Command> PeekCommand::Get(std::string command)
{
	auto result = _commands.find(command);
	if (result == _commands.end())
		throw UVar();
	return result->second;
}