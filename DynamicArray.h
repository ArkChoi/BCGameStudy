#pragma once

struct DaynamicData
{
	int Data;
	DaynamicData* BackData;
};

class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	DaynamicData* StartPoint = nullptr;

	int Size = 0;

	int Index = 0;

	void PushBack(int Value);
	void AllDataPrint();
};