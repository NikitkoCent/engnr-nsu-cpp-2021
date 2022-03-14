#include "UserInterface.h"

std::string UserInterface::In()
{
	std::string in;
	std::getline(std::cin, in);
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << " > ";
	std::cin >> in;
	std::cin.seekg(std::cin.end);
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
