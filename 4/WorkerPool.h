#pragma once

#include "Worker.h"
#include "WorkerResult.h"
#include "Task.h"
#include "UserInterface.h"
#include <queue>
#include <mutex>

class WorkerPool
{
private:
	std::queue<Worker*> freeWorkers;
	Worker** workers;
	size_t count;

	std::queue<Task*> tasks;
	UserInterface* ui;
	volatile bool isWorking;
	volatile bool stopped;
	std::mutex mut;

public:
	WorkerPool(size_t count);
	void SetUI(UserInterface* ui);

	bool Start();
	long long AddTask(Task* task);
	void BackToWork(Worker* worker, WorkerResult* result);

	bool IsWorking();
	void Wait();

	void Stop();
	void Cancel();

	~WorkerPool();
};
