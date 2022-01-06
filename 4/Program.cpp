#include <string>
#include <fstream>
#include <queue>
#include <iostream>
#include "WorkerPool.h"
#include "UserInterface.h"

int main()
{
	WorkerPool pool(10);
	UserInterface ui = UserInterface();
	pool.SetUI(&ui);
	pool.Start();
	ui.SetPool(&pool, WorkerPool::AddTask, WorkerPool::Cancel);
	ui.Work();
	pool.Stop();
}