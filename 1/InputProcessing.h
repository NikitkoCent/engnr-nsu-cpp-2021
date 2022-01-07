#pragma once
#include <string>
#include "Help.h"
#include <fstream>
#include <iostream>
using namespace std;

class InputProcessing
{
private: 
	int argc_;
	char** argv_; 
	bool metod_;
	fstream file;
public:
	InputProcessing(int argc, char* argv[]);
	int checkInput();
	bool Metod();
	fstream* File();
	~InputProcessing();
};

