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
	std::unique_lock<std::mutex> lock(waitingMutex);

	while (!stopped)
	{
		waitingThreads.wait(lock);
		while (tasks.Dequeue(task))
		{
			lock.unlock();
			task();
			lock.lock();
		}
	}
}

size_t ThreadPool::AddTask(std::function<void()> task)
{
	if (stopped)
		return 0;
	std::unique_lock<std::mutex> lock(waitingMutex);
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
