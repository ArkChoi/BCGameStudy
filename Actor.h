#pragma once

#include "Vector.h"
#include <vector>
//2D
class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();

	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto Component : Components)
		{
			if (dynamic_cast<T*>(Component))
			{
				return dynamic_cast<T*>(Component);
			}
		}

		return nullptr;
	}

	//virtual void SetSimulatePhysics();

	bool CheakCollsion(const AActor* Ohter); //지금은 틱에서 체크하는 충돌처리 엔진은 완전히 다르다.

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void SetupAttachment(UComponent* InComponent);

	std::vector<class UComponent*> Components;
protected:

	FVector2D Location;

public:

	//SDL_Color Color = {255, 255, 255, 255};

};

