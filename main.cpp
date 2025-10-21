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

void Print(int A, int B, int (*FP)(int, int))
{
	std::cout << FP(A, B) << std::endl;
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

int main()
{
	Print(2, 3, Sum);

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}