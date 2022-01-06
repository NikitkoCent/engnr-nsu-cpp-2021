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

	static void CommitResult(WorkerPool* pool, Worker* worker, WorkerResult* result);
	void BackToWork(Worker* worker, WorkerResult* result);
	size_t AddTask(Task* task);
public:
	WorkerPool(size_t count);
	void SetUI(UserInterface* ui);

	bool Start();
	static size_t AddTask(WorkerPool* pool, Task* task);

	bool IsWorking();
	void Wait();

	void Stop();
	void Cancel();
	static void Cancel(WorkerPool* pool);

	~WorkerPool();
};
