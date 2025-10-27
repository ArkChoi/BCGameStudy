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

	TDynamicArray<float> Data;
	TDynamicArray<float> Data2 = Data;

	Data2 = Data;

	return 0;
}