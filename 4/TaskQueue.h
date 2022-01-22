#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <utility>
#include <functional>
#include <atomic>

class TaskQueue
{
private:
	std::queue<std::function<void()>> taskQueue;
	std::mutex queueMutex;
	std::condition_variable dequeueWait;
	std::atomic<bool> stopped;
public:
	TaskQueue() : stopped(false) {};
	~TaskQueue();

	size_t Enqueue(std::function<void()> task);
	bool Dequeue(std::function<void()>& task);
	void Clear();
	void Stop();
};