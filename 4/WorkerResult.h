#pragma once
#include <string>

class WorkerResult
{
private:
	std::string dir;
	long long size;

	std::string err;
	bool isErr;
public:
	WorkerResult(std::string dir, long long size);
	WorkerResult(std::string dir, std::string err);

	bool IsError();
	std::string GetError();

	std::string Dir();
	long long Size();
};
