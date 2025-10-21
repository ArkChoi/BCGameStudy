#include <iostream>
#include <vector>
#include <list>

#include "Engine.h"
#include "DynamicArray.h"

int main()
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}