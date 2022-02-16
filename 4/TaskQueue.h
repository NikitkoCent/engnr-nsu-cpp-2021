#pragma once

#include <mutex>
#include <queue>
#include <functional>

class TaskQueue
{
private:
	std::queue<std::function<void()>> taskQueue;
	std::mutex queueMutex;
public:
	TaskQueue() = default;
	~TaskQueue() = default;

	size_t Enqueue(std::function<void()> task);
	bool Dequeue(std::function<void()>& task);
	void Clear();
};