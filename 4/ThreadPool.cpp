#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threadsCount)
{
	stopped = false;
	threads.resize(threadsCount);
	for (auto& thread : threads)
		thread = (std::thread(&ThreadPool::ThreadWork, this));
}

void ThreadPool::ThreadWork()
{
	std::function<void()> task;
	while (!stopped)
	{
		std::unique_lock<std::mutex> waitingMutex;
		waitingThreads.wait(waitingMutex);
		while (tasks.Dequeue(task))
			task();
	}
}

size_t ThreadPool::AddTask(std::function<void()> task)
{
	if (stopped)
		return 0;
	auto result = tasks.Enqueue(task);
	waitingThreads.notify_one();
	return result;
}

void ThreadPool::Cancel()
{
	tasks.Clear();
}

void ThreadPool::Stop()
{
	stopped = true;
	waitingThreads.notify_all();
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