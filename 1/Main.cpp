#include <iostream>
#include "InputProcessing.h"
#include "Hasher.h"
#include <string.h>

int main(int argc, char *argv[])
{
	InputProcessing* date = new InputProcessing(argc, argv);
	int resultCheck = date->checkInput();
	if (resultCheck < 0)
		return 0;
	else
		if (resultCheck > 0)
			return resultCheck;
	Hasher* hash = new Hasher(date->File(), date->Metod());
	std::cout << std::hex << hash->Hash();
	delete(date);
	delete(hash);
	return 0;
}
