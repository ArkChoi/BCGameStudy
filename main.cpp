#include <iostream>
#include "Engine.h"

int Sum(int A, int B)
{
	return A + B;
}

int Sub(int A, int B)
{
	return A - B;
}

void Sort(bool (*Compare)(int , int ), int A, int B)
{
	int Numbers[10] = { 10, 2, 1, 5, 6, 3, 9, 7, 8, 4 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Compare(A,B))
			{
				int Temp = Numbers[i];
				Numbers[i] = Numbers[j];
				Numbers[j] = Temp;
			}
		}
	}
}

bool Compare(int A, int B)
{
	return A > B;
}

bool Less(int A, int B)
{
	return A < B;
}

//Callback
void OnReceive(int *(Callback)())
{
	bool bEnd = false;
	while (!bEnd)
	{

	}
	Callback();
}

//void Print(void* Numbers, int _SizeOfElement, int _NumberOfElement)
//{
//	for (int i = 0; i < _NumberOfElement; i++)
//	{
//		std::cout << *(Numbers+(i*_SizeOfElement)) << std::endl;
//	}
//}

////meta programing
//template<typename T>
//void Print(T* Numbers, int Size)
//{
//	for (int i = 0; i < Size; i++)
//	{
//		std::count << Numbers[i] << std::endl;
//	}
//}

template<typename T>
class TemplateClass
{
public:
	T Data;
};

int main()
{
	TemplateClass<int> Temp;
	Temp.Data = 10;

	TemplateClass<float> fTemp;
	fTemp.Data = 10.0f;

	/*GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;*/

	return 0;
}