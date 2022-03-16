#pragma once

#include <string>
#include <iostream>
#include <mutex>

class UserInterface
{
private:
	std::mutex mutex;
	bool firstFlag;
public:
	UserInterface();
	std::string In();
	void Out(std::string str);
	void Err(std::string str);
};
