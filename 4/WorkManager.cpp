#include "WorkManager.h"

std::string WorkManager::Help()
{
	return
		"\n\n                 --HELP--"
		"\nto enter the input mode, you must press \"enter\""
		"\nin input mode, the \" > \" sign is displayed in the line"
		"\n"
		"\nin input mode you can enter the following commands:"
		"\n"
		"\n\t<path to directory> = put path to queue"
		"\n\t:help               = call the help"
		"\n\t:cancel             = cancel all waiting tasks"
		"\n\t:exit               = exit program"
		"\n"
		"\nthe program will go into standby mode"
		"\nafter completing the input and pressing \"enter\""
		"\n";
}

bool DirSize(std::filesystem::path path, uintmax_t& result)
{
	if (!std::filesystem::exists(path))
	{
		result = 0;
		return false;
	}
	uintmax_t size = 0;
	for (auto& p : std::filesystem::recursive_directory_iterator(path))
		if (!std::filesystem::is_directory(p))
			size += std::filesystem::file_size(p);
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
			ui.Out(Help());
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
