#include "DynamicArray.h"

#include <iostream>

TDynamicArray::TDynamicArray()
{
	Data = new int[Size];
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Index < Size)
	{
		Data[Index] = Value;
		Index++;
	}
	else
	{
		Size += 1;
		int* NewArray = new int[Size];
		for (int i = 0; i < (Size-1); i++)
		{
			NewArray[i] = Data[i];
		}
		delete[] Data;

		Data = NewArray;

		Data[Index] = Value;
		Index++;
	}
}

void TDynamicArray::AllValuePrint()
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << Data[i] << std::endl;
	}
}
