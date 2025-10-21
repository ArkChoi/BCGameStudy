#include <iostream>
#include <vector>

#include "Engine.h"
#include "DynamicArray.h"

int main()
{
	/*GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;*/

	std::vector <int>test;
	test.push_back(1);

	TDynamicArray Test;
	Test.PushBack(1);
	Test.PushBack(3);
	Test.PushBack(5);
	Test.PushBack(7);

	Test.AllValuePrint();

	std::cout << std::endl;
	std::cout << Test.Size << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		Test.PushBack(i);
	}

	Test.AllValuePrint();

	std::cout << std::endl;
	std::cout << Test.Size << std::endl;
	std::cout <<  std::endl;

	return 0;
}