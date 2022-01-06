#include <string>
#include <fstream>
#include <queue>
#include <iostream>
#include "WorkerPool.h"
#include "UserInterface.h"

int main()
{
	WorkerPool pool(10);
	UserInterface ui = UserInterface(&pool);
	pool.SetUI(&ui);
	pool.Start();
	ui.Work();
	pool.Stop();
}