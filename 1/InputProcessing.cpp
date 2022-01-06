#include "InputProcessing.h"
#include <string>
using namespace std;

int mcmp(const char* x_, const char* y_)
{
	auto x = x_;
	auto y = y_;
	for (; x[0] != '\0'; x++)
		if (y[0] == '\0' || y[0] != x[0])
			return -1;
		else
			y++;
	if (y[0] == '\0')
		return 0;
	else
		return -1;
}

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
	if (argc_ == 2 && !mcmp(argv_[1], "-h")) //проверка на запрос help
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
	if (!mcmp(argv_[1],"-m"))
	{
		mode = argv_[2];
		name = argv_[3];
	}
	else if (!mcmp(argv_[2],"-m"))
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
	if ((!mcmp(mode,"adler32") || !mcmp(mode,"Adler32")))
		metod_ = true;
	else if (!mcmp(mode,"sum64") || !mcmp(mode,"Sum64"))
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
