#pragma once

#include "WorkerResult.h"
#include "Task.h"
#include <mutex>

class WorkerPool;

class UserInterface
{
private:
	WorkerPool* pool;
	std::mutex mut;
public:
	UserInterface(WorkerPool* pool);
	void TakeResult(WorkerResult* result);
	void Work();
};

int mcmp(const char* x_, const char* y_);
