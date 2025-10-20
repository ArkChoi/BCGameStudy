#include <iostream>
#include "Engine.h"

#include <vector>

int main()
{
	FEngine* MyEngine;
	MyEngine = new FEngine();

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}