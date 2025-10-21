//#include "DynamicArray.h"
//
//#include <iostream>
//
//TDynamicArray::TDynamicArray()
//{
//	Data = new int[Size];
//}
//
//TDynamicArray::~TDynamicArray()
//{
//}
//
//void TDynamicArray::PushBack(T Value)
//{
//	if (Index < Capacity)
//	{
//		Data[Index] = Value;
//		Index++;
//		Size++;
//	}
//	else
//	{
//		if (Capacity == 0)
//		{
//			Capacity = 1;
//		}
//		int* NewArray = new int[Capacity*2];
//		for (int i = 0; i < Size; i++)
//		{
//			NewArray[i] = Data[i];
//		}
//		delete[] Data;
//
//		Data = NewArray;
//
//		Data[Index] = Value;
//		Index++;
//		Size++;
//
//		Capacity *= 2;
//	}
//}
//
//void TDynamicArray::AllValuePrint()
//{
//	for (int i = 0; i < Size; i++)
//	{
//		std::cout << Data[i] << std::endl;
//	}
//}
