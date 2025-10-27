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

	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

	//virtual void SetSimulatePhysics();

	bool CheakCollsion(const AActor* Ohter); //지금은 틱에서 체크하는 충돌처리 엔진은 완전히 다르다.

	virtual void ActorBeginOverlap();
	virtual void Hit();

protected:

	int ZOrder;
	FVector2D Location;
	char Shape;

public:
	bool bIsCollision = false; //충돌감지를 위한 변수 | 본래는 protected 이 맞다만.. 함수 만들기 싫어서 넘긴다고.
	bool bIsOverlap = true;   //현실에는 없다만 동전이랑 충돌해서 못 먹을 수는 없으니 생긴 개념
};

