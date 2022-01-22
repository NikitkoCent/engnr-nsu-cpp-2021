#pragma once

#include <utility>
#include <filesystem>

#include "UserInterface.h"
#include "ThreadPool.h"

class WorkManager
{
private:
	UserInterface ui;
	ThreadPool threadPool;

	void WorkProcess(std::string path);
	void Help();
public:
	WorkManager(size_t threadCount) : threadPool(threadCount) {};
	~WorkManager() = default;
	void Work();
};