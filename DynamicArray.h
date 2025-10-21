#pragma once

class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int* Data;

	int Size = 0; //실 자료 입력 양
	int Capacity = 0; //자료가 잡혀있는 크기

	int Index = 0;

	void PushBack(int Value);
	void AllValuePrint();
};