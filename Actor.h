#pragma once

#include "Vector.h"
//2D

class AActor
{
public:
	AActor();
	virtual ~AActor();

	void Tick();

	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

private:
	FVector2D Location;
};

