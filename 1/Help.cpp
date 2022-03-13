#include "Help.h"

std::string Help::Get()
{
	return std::string("Program for calculating hash of file.")
		+ "\nWariants of using:"
		+ "\n ./hasher - h"
		+ "\n ./hasher <filename> -m <mode>"
		+ "\n ./hasher - m <mode> <filename>"
		+ "\nwhere <mode> : { adler32, sum64 }";
}