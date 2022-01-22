#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threadsCount)
{
	threads.resize(threadsCount);
	for (auto& thread : threads)
		thread = std::move(std::thread(&ThreadPool::ThreadWork, this));
}

void ThreadPool::ThreadWork()
{
	std::function<void()> task;
	while (tasks.Dequeue(task))
		task();
}

size_t ThreadPool::AddTask(std::function<void()> task)
{
	return tasks.Enqueue(task);
}

void ThreadPool::Cancel()
{
	tasks.Clear();
}

void ThreadPool::Stop()
{
	tasks.Stop();
}

void ThreadPool::WaitAll()
{
	for (auto& thread : threads)
		thread.join();
}

ThreadPool::~ThreadPool()
{
	Stop();
	WaitAll();
}