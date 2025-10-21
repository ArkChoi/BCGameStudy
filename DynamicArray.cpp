#include "DynamicArray.h"

#include <iostream>

TDynamicArray::TDynamicArray()
{
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (StartPoint == nullptr)
	{
		DaynamicData* NewNumber = new DaynamicData;
		NewNumber->Data = Value;
		NewNumber->BackData = nullptr;
		StartPoint = NewNumber;
		Size++;
	}
	else
	{
		DaynamicData* Temp = StartPoint;
		DaynamicData* NewNumber = new DaynamicData;
		NewNumber->Data = Value;
		NewNumber->BackData = nullptr;
		while (!(Temp->BackData == nullptr))
		{
			Temp = (Temp->BackData);
		}
		Temp->BackData = NewNumber;
		Size++;
	}
}

void TDynamicArray::AllDataPrint()
{
	DaynamicData* Temp = StartPoint;
	while (!(Temp->BackData == nullptr))
	{
		std::cout << Temp->Data << std::endl;
		Temp = (Temp->BackData);
	}
	std::cout << Temp->Data << std::endl;
}
