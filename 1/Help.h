#pragma once
#include <string>
#include <iostream>

class Help
{
private:
	static std::string generalHelp_;

public:
	static void print(int error);
	
};

