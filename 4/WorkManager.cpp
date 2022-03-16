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

uintmax_t WorkManager::DirSize(std::filesystem::path path)
{
	return DirSize(path, path);
}

uintmax_t WorkManager::DirSize(std::filesystem::path path, std::filesystem::path local_path)
{
	uintmax_t size = 0;

	if (!std::filesystem::exists(local_path))
	{
		ui.Err("\"" + path.string() + "\" : directory doesnot exist");
		return size;
	}

	std::filesystem::directory_iterator p_iter;
	
	try
	{
		if (!std::filesystem::is_directory(local_path))
			return std::filesystem::file_size(local_path);
		else
			p_iter = std::filesystem::directory_iterator(local_path);
	}
	catch (std::filesystem::filesystem_error&)
	{
		ui.Err("\"" + path.string() + "\" : cant calculate \"" + local_path.string() + "\"");
		return size;
	}

	std::filesystem::directory_entry last_p;
	bool flag = true;

	try
	{
		for (auto& p : p_iter)
		{
			if (flag)
				flag = false;
			else
			{
				if (p == last_p)
					return size;
			}

			last_p = p;

			if (std::filesystem::is_directory(p))
				size += DirSize(path, p);
			else
			{
				try
				{
					size += std::filesystem::file_size(p);
				}
				catch (std::filesystem::filesystem_error&)
				{
					ui.Err("\"" + path.string() + "\" : cant calculate \"" + p.path().string() + "\"");
				}
			}
		}
	}
	catch (std::filesystem::filesystem_error&)
	{
		ui.Err("\"" + path.string() + "\" : calculating \"" + local_path.string() + "\" stopped, cant calculate \"" + (*p_iter).path().string() + "\"");
	}

	return size;
}

void WorkManager::WorkProcess(std::string path)
{
	try
	{
		ui.Out("\"" + path + "\" : " + std::to_string(DirSize(path)) + " bytes");
	}
	catch (...)
	{
		ui.Err("\"" + path + "\" : unexpected error");
	}
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
