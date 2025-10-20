#include <iostream>
#include "Engine.h"

int main()
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}