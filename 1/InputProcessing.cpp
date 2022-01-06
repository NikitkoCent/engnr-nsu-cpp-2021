#include "InputProcessing.h"
#include <string>
using namespace std;

InputProcessing::InputProcessing(int argc, char* argv[])
{
	argc_ = argc;
	argv_ = argv;
	metod_ = 0;
}

int InputProcessing::checkInput()
{
	std::string name;
	char* mode;
	if (argc_ == 2 && !strcmp(argv_[1],"-h")) //проверка на запрос help
	{
		Help::print(-1);
		return -1;
	}
	if (argc_ != 4) //проверка на кол-во элементов запроса
	{
		Help::print(1);
		return 1;
	}
	//разбиение на адрес и метод
	if (!strcmp(argv_[1],"-m"))
	{
		mode = argv_[2];
		name = argv_[3];
	}
	else if (!strcmp(argv_[2],"-m"))
	{
		name = argv_[1];
		mode = argv_[3];
	}
	//если нет метода
	else
	{
		Help::print(1);
		return 1;
	}
	
	file.open(name, std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		Help::print(2);
		return 2;
	}
	if ((!strcmp(mode,"adler32") || !strcmp(mode,"Adler32")))
		metod_ = true;
	else if (!strcmp(mode,"sum64") || !strcmp(mode,"Sum64"))
		metod_ = false;
	else
	{
		Help::print(1);
		return 1;
	}
	return 0;
}
bool InputProcessing::Metod()
{
	return (metod_);
}
fstream* InputProcessing::File()
{
	return (&file);
}

InputProcessing::~InputProcessing()
{
	file.close();
}
