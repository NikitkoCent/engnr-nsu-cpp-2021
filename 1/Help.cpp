#include "Help.h"
std::string Help::generalHelp_ = "Help:\n'-h' - output help\n'./hasher <filename> -m <mode>' or\n './hasher -m <mode> <filename>' - where 'mode' - hash function, 'filename' -  input file";

void Help::print(int error)
{
	switch (error)
	{
	case(-1):
		std::cout << generalHelp_ << std::endl;
		break;
	case(1):
		std::cerr<<"incorrect input. Read 'help' please\n"<< generalHelp_ << std::endl;
	}

}
