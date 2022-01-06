#pragma once

#include "Task.h"
#include "WorkerResult.h"
#include <filesystem>
#include <thread>
#include <mutex>

class WorkerPool;

class Worker
{
private:
	WorkerPool* pool;
	void (*commit) (WorkerPool*, Worker*, WorkerResult*);
	volatile bool isWork;
	volatile bool stopped;
	std::thread myThread;

	Task* task;
	bool canceled;
	std::mutex taskMut;

	void Work();
	bool FinishWork();
	void FinishWorkWithResult(WorkerResult* result);
	void FreeTask();
	bool CheckCancel();

	long long DirSize(std::filesystem::path path);
public:
	Worker(WorkerPool* pool, void (*commit) (WorkerPool*, Worker*, WorkerResult*));
	bool GiveTask(Task* task);
	bool IsWork();
	void Cancel();
	void Stop();
	~Worker();
};
