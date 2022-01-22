#include "UserInterface.h"

std::string UserInterface::In()
{
	getchar();
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << " > ";
	std::string in;
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