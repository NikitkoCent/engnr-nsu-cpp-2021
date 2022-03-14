#pragma once

#include <vector>
#include <mutex>
#include <utility>
#include <functional>
#include <thread>
#include <atomic>
#include <condition_variable>

#include "TaskQueue.h"

class ThreadPool
{
private:
	TaskQueue tasks;
	std::vector<std::thread> threads;

	std::mutex waitingMutex;
	std::condition_variable waitingThreads;
	std::atomic<bool> stopped;

	void ThreadWork();
public:
	ThreadPool(size_t threadsCount);
	~ThreadPool();
	
	size_t AddTask(std::function<void()> task);
	void Cancel();
	void Stop();
	void WaitAll();
};
