#include "UserInterface.h"
#include "WorkerPool.h"
#include <iostream>
#include <string>

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

UserInterface::UserInterface(WorkerPool* pool)
{
	this->pool = pool;
}

void UserInterface::TakeResult(WorkerResult* result)
{
	mut.lock();
	if (result->IsError())
		std::cerr << result->Dir() << " : " << result->GetError() << std::endl;
	else
		std::cout << result->Dir() << " : " << result->Size() << std::endl;
	mut.unlock();
	delete result;
}

void UserInterface::Work()
{
	char* input = new char[1024];
	while (true)
	{
		//getchar();
		//mut.lock();
		//std::cout << "=> ";
		std::cin >> input;
		//mut.unlock();

		if (!mcmp(input, ":exit"))
		{
			delete[] input;
			return;
		}
		else if (!mcmp(input, ":cancel"))
			pool->Cancel();
		else
		{
			auto key = pool->AddTask(new std::string(input));
			mut.lock();
			if (key < 0)
				std::cerr << input << " : process stopped before accepting task" << std::endl;
			else
				std::cout << input << " : task accepted, " << key << " position in queue" << std::endl;
			mut.unlock();
		}
		std::cin.seekg(std::cin.end);
	}
}