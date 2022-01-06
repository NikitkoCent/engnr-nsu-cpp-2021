#include "UserInterface.h"
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

UserInterface::UserInterface()
{
	pool = NULL;
}

void UserInterface::SetPool(WorkerPool* pool, size_t (*newTask) (WorkerPool* pool, Task* task), void (*cancel) (WorkerPool* pool))
{
	this->newTask = newTask;
	this->cancel = cancel;
	this->pool = pool;
}

void UserInterface::TakeResult(WorkerResult* result)
{
	mut.lock();
	if (result->IsError())
		std::cout << result->Dir() << " : " << result->GetError() << std::endl;
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
		/*
		mut.lock();
		std::cin >> input;
		mut.unlock();
		*/
		if (!mcmp(input, ":exit"))
		{
			delete[] input;
			return;
		}
		else if (!mcmp(input, ":cancel"))
			cancel(pool);
		else
			newTask(pool, new std::string(input));
		std::cin.seekg(std::cin.end);
	}
}