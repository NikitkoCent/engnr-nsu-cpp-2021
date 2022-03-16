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

	uintmax_t DirSize(std::filesystem::path path, std::filesystem::path local_path);
	uintmax_t DirSize(std::filesystem::path path);
	void WorkProcess(std::string path);
public:
	WorkManager(size_t threadCount) : threadPool(threadCount) {};
	static std::string Help();
	void Work();
};
