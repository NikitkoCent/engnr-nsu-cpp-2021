#pragma once

#include "WorkerResult.h"
#include "Task.h"
#include <mutex>

class WorkerPool;

class UserInterface
{
private:
	size_t (*newTask) (WorkerPool* pool, Task* task);
	void (*cancel) (WorkerPool* pool);
	WorkerPool* pool;
	std::mutex mut;
public:
	UserInterface();
	void SetPool(WorkerPool* pool, size_t (*newTask) (WorkerPool* pool, Task* task), void (*cancel) (WorkerPool* pool));
	void TakeResult(WorkerResult* result);
	void Work();
};

