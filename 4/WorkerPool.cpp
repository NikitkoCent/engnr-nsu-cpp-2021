#include "WorkerPool.h"
#include <chrono>
#include <thread>

WorkerPool::WorkerPool(size_t count)
{
	this->count = count;
	workers = (Worker**)malloc(sizeof(Worker*) * count);
	for (size_t i = 0; i < count; i++)
	{
		workers[i] = new Worker(this, CommitResult);
		freeWorkers.push(workers[i]);
	}

	ui = NULL;
	isWorking = false;
	stopped = false;
}

void WorkerPool::SetUI(UserInterface* ui)
{
	this->ui = ui;
}

bool WorkerPool::Start()
{
	if (!ui)
		return false;
	std::lock_guard<std::mutex> lock(mut);
	while ((tasks.size() != 0) && (freeWorkers.size() != 0))
	{
		freeWorkers.front()->GiveTask(tasks.front());
		freeWorkers.pop();
		tasks.pop();
	}
	isWorking = true;
	return true;
}

void WorkerPool::CommitResult(WorkerPool* pool, Worker* worker, WorkerResult* result)
{
	pool->BackToWork(worker, result);
}

void WorkerPool::BackToWork(Worker* worker, WorkerResult* result)
{
	ui->TakeResult(result);
	std::lock_guard<std::mutex> lock(mut);
	if (stopped && (tasks.size() == 0))
		return;
	if (tasks.size() != 0)
	{
		worker->GiveTask(tasks.front());
		tasks.pop();
	}
	else
		freeWorkers.push(worker);
}

size_t WorkerPool::AddTask(WorkerPool* pool, Task* task)
{
	return pool->AddTask(task);
}

size_t WorkerPool::AddTask(Task* task)
{
	std::lock_guard<std::mutex> lock(mut);
	if (stopped)
	{
		delete task;
		return -1;
	}
	if (freeWorkers.size() != 0)
	{
		freeWorkers.front()->GiveTask(task);
		freeWorkers.pop();
		return 0;
	}
	else
	{
		tasks.push(task);
		return tasks.size();
	}
}

bool WorkerPool::IsWorking()
{
	return isWorking;
}

void WorkerPool::Wait()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(250));
		mut.lock();
		bool key = freeWorkers.size() == count;
		mut.unlock();
		if (key) return;
	}
}

void WorkerPool::Cancel(WorkerPool* pool)
{
	pool->Cancel();
}

void WorkerPool::Cancel()
{
	std::lock_guard<std::mutex> lock(mut);
	for (size_t i = 0; i < count; i++)
		workers[i]->Cancel();
}

void WorkerPool::Stop()
{
	stopped = true;
}

WorkerPool::~WorkerPool()
{
	stopped = true;
	mut.lock();
	for (size_t i = 0; i < count; i++)
		workers[i]->Stop();
	mut.unlock();
	Wait();
	mut.lock();
	for (size_t i = 0; i < count; i++)
		delete workers[i];
	mut.unlock();
	free(workers);
}
