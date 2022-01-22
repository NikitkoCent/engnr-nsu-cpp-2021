#include "WorkManager.h"

bool DirSize(std::filesystem::path path, uintmax_t& result)
{
	if (!std::filesystem::exists(path))
	{
		result = 0;
		return false;
	}
	uintmax_t size = 0;
	for (auto& p : std::filesystem::recursive_directory_iterator(path))
	{
		if (std::filesystem::is_directory(p))
		{
			uintmax_t inSize;
			if (!DirSize(p.path(), inSize))
				return false;
			size += inSize;
		}
		size += std::filesystem::file_size(p);
	}
	result = size;
	return true;
}

void WorkManager::WorkProcess(std::string path)
{
	uintmax_t result;
	if (DirSize(path, result))
		ui.Out("\"" + path + "\" : " + std::to_string(result) + " bytes");
	else
		ui.Err("\"" + path + "\" : file does not exist");
}

void WorkManager::Help()
{
	ui.Out(" --help-- ");
}

void WorkManager::Work()
{
	while (true)
	{
		auto in = ui.In();
		if (in.compare(":exit") == 0)
		{
			threadPool.Stop();
			return;
		}
		else if (in.compare(":cancel") == 0)
			threadPool.Cancel();
		else if (in.compare(":help") == 0)
			Help();
		else
		{
			auto pos = threadPool.AddTask([&, in] { WorkProcess(in); });
			if (pos == 0)
				ui.Out("\"" + in + "\" : rejected");
			else
				ui.Out("\"" + in + "\" : accepted, " + std::to_string(pos) + " in queue");
		}
	}
}