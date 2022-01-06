#include "WorkerResult.h"

WorkerResult::WorkerResult(std::string dir, long long size)
{
	this->dir = dir;
	this->size = size;
	err = "";
	isErr = false;
}

WorkerResult::WorkerResult(std::string dir, std::string err)
{
	this->dir = dir;
	size = -1;
	this->err = err;
	isErr = true;
}

bool WorkerResult::IsError()
{
	return isErr;
}

std::string WorkerResult::GetError()
{
	return err;
}

std::string WorkerResult::Dir()
{
	return dir;
}

long long WorkerResult::Size()
{
	return size;
}