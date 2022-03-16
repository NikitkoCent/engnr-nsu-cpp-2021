#include "UserInterface.h"

UserInterface::UserInterface()
{
	firstFlag = false;
}

std::string UserInterface::In()
{
	std::string in;
	if (firstFlag)
		std::getline(std::cin, in);
	else
		firstFlag = true;
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << " > ";
	std::getline(std::cin, in);
	return in;
}

void UserInterface::Out(std::string str)
{
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << str << std::endl;
}

void UserInterface::Err(std::string str)
{
	std::lock_guard<std::mutex> lock(mutex);
	std::cerr << str << std::endl;
}
