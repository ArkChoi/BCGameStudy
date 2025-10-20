#pragma once

struct FVector2D
{
public:
	FVector2D(int InX=0, int InY=0) : X(InX), Y(InY)
	{
		
	}
	virtual ~FVector2D()
	{

	}
	int X;
	int Y;
};