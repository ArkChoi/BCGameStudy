#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>

AActor::AActor()
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

//void AActor::SetSimulatePhysics()
//{
//}

bool AActor::CheakCollsion(const AActor* OtherActor)
{
	if (OtherActor->bIsOverlap)
	{
		return false;
	}

	if (this != OtherActor && OtherActor->bIsCollision && bIsCollision
		&& this->Location == OtherActor->Location)
	{
		return true;
	}
	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
