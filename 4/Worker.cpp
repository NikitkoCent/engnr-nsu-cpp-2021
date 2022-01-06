#include "Worker.h"
#include "WorkerPool.h"
#include <chrono>

namespace sf = std::filesystem;

constexpr auto FILE_NOT_FOUND = -1;
constexpr auto PROCESS_CANCELED = -2;

Worker::Worker(WorkerPool* pool)
{
	this->pool = pool;
	isWork = true;
	stopped = false;
	canceled = false;
	task = NULL;
	myThread = std::thread([=] { Work(); });
}

long long Worker::DirSize(sf::path path)
{
	if (!sf::exists(path))
		return FILE_NOT_FOUND;
	long long size = 0;
	for (auto& p : sf::recursive_directory_iterator(path))
	{
		if (CheckCancel())
			return PROCESS_CANCELED;
		if (sf::is_directory(p))
		{
			auto key = DirSize(p.path());
			if (key < 0)
				return key;
			size += key;
		}
		size += sf::file_size(p);
	}
	return size;
}

void Worker::Work()
{
	while (true)
	{
		std::string it;

		while (true)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(250));
			std::lock_guard<std::mutex> lock(taskMut);
			if (task)
			{
				it = std::string(*task);
				break;
			}
			if (stopped)
				return;
		}

		auto size = DirSize(it);
		if (size < 0)
		{
			switch (size)
			{
			case FILE_NOT_FOUND:
				FinishWorkWithResult(new WorkerResult(it, "file not found"));
				break;
			case PROCESS_CANCELED:
				FinishWorkWithResult(new WorkerResult(it, "process canceled"));
				break;
			default:
				FinishWorkWithResult(new WorkerResult(it, "unexpected error"));
				break;
			}
			continue;
		}
		FinishWorkWithResult(new WorkerResult(it, size));
	}
}

bool Worker::FinishWork()
{
	if (CheckCancel())
		return false;
	FreeTask();
	return true;
}

void Worker::FinishWorkWithResult(WorkerResult* result)
{
	if (FinishWork())
		pool->BackToWork(this, result);
}

void Worker::FreeTask()
{
	taskMut.lock();
	if (task)
	{
		delete task;
		task = NULL;
	}
	taskMut.unlock();
}

bool Worker::CheckCancel()
{
	if (!canceled)
		return false;

	canceled = false;
	return true;
}

bool Worker::GiveTask(Task* task)
{
	std::lock_guard<std::mutex> lock(taskMut);
	if (this->task || stopped || !isWork)
		return false;
	this->task = task;
	return true;
}

bool Worker::IsWork()
{
	return isWork;
}

void Worker::Cancel()
{
	std::lock_guard<std::mutex> lock(taskMut);
	if (task)
	{
		canceled = true;
		delete task;
		task = NULL;
	}
}

void Worker::Stop()
{
	stopped = true;
}

Worker::~Worker()
{
	Stop();
	myThread.join();
	FreeTask();
}