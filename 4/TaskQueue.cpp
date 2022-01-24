#include "TaskQueue.h"

size_t TaskQueue::Enqueue(std::function<void()> task)
{
	std::lock_guard<std::mutex> lock(queueMutex);
	if (stopped)
		return 0;
	taskQueue.push(task);
	dequeueWait.notify_one();
	return taskQueue.size();
}

bool TaskQueue::Dequeue(std::function<void()>& task)
{
	std::unique_lock<std::mutex> lock(queueMutex);
	while (taskQueue.empty() && !stopped)
		dequeueWait.wait(lock);
	if (taskQueue.empty())
		return false;
	task = (taskQueue.front());     /////
	taskQueue.pop();
	return true;
}

void TaskQueue::Clear()
{
	std::lock_guard<std::mutex> lock(queueMutex);
	while (!taskQueue.empty())
		taskQueue.pop();
}

void TaskQueue::Stop()
{
	std::unique_lock<std::mutex> lock(queueMutex);
	stopped = true;
	dequeueWait.notify_all();
}

TaskQueue::~TaskQueue()
{
	Stop();
}