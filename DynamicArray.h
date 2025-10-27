#pragma once
#include "DynamicArray.h"

#include <iostream>

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray() 
	{
	
	}

	//깊은 복사, 복사 생성자
	TDynamicArray(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;
		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(this->Data, RHS.Data, Size*sizeof(int));
	}

	virtual ~TDynamicArray()
	{
		if (Data) 
		{
			delete[] Data;
		}
	}

protected:
	T* Data = nullptr;

	size_t Size = 0; //실 자료 입력 양 + C++에서 자료형 계산때 미리 정의해둔 size_t를 사용한다고 한다.
	size_t Capacity = 0; //자료가 잡혀있는 크기

	int CurrentIndex = 0;

public:
	size_t GetSize()
	{
		return Size;
	}
	size_t GetCapacity()
	{
		return Capacity;
	}

	//무슨 오퍼레이터? 연산자 오버로딩이라고 불러오는 시스템을 바꾸는 듯 합니다.
	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (CurrentIndex < Capacity)
		{
			Data[CurrentIndex] = Value;
			CurrentIndex++;
			Size++;
		}
		else
		{
			if (Capacity == 0)
			{
				Capacity = 1;
			}
			T* NewArray = new T[Capacity * 2];
			for (size_t i = 0; i < Size; i++)
			{
				NewArray[i] = Data[i];
			}
			delete[] Data;

			Data = NewArray;

			Data[CurrentIndex] = Value;
			CurrentIndex++;
			Size++;

			Capacity *= 2;
		}
	}

	void AllValuePrint()
	{
		for (size_t i = 0; i < Size; i++)
		{
			std::cout << Data[i] << std::endl;
		}
	}
};