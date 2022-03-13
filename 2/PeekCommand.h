#pragma once

#include <memory>
#include <map>

#include "Command.h"

class PeekCommand
{
private:
	std::map<std::string, std::shared_ptr<Command>> _commands;
public:
	PeekCommand(MemStack& memory);
	std::shared_ptr<Command> Get(std::string command);
};

