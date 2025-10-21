#include <iostream>

#include "Engine.h"
#include "DynamicArray.h"

int main()
{
	/*GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;*/

	TDynamicArray Test;
	Test.PushBack(1);
	Test.PushBack(3);
	Test.PushBack(5);
	Test.PushBack(7);

	Test.AllDataPrint();

	return 0;
}