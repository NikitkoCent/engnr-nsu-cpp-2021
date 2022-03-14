#include "TaskQueue.h"

size_t TaskQueue::Enqueue(std::function<void()> task)
{
	std::lock_guard<std::mutex> lock(queueMutex);
	taskQueue.push(task);
	return taskQueue.size();
}

bool TaskQueue::Dequeue(std::function<void()>& task)
{
	std::lock_guard<std::mutex> lock(queueMutex);
	if (taskQueue.empty())
		return false;
	task = taskQueue.front();
	taskQueue.pop();
	return true;
}

void TaskQueue::Clear()
{
	std::lock_guard<std::mutex> lock(queueMutex);
	while (!taskQueue.empty())
		taskQueue.pop();
}
