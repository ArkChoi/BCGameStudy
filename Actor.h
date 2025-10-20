#pragma once

#include "Vector.h"
//2D

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	__forceinline char GetShape()
	{
		return Shape;
	}

	void SetShape(char Temp)
	{
		Shape = Temp;
	}

protected:

	int ZOrder;
	FVector2D Location;
	char Shape;
};

