#pragma once

class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int* Data;
	int Size = 0;
	int Index = 0;

	void PushBack(int Value);
	void AllValuePrint();
};