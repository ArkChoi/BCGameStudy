#include "Actor.h"
#include "Engine.h"
#include "Component.h"

#include <iostream>
#include <Windows.h>

AActor::AActor()
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::Tick()
{
}

//void AActor::SetSimulatePhysics()
//{
//}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}

void AActor::SetupAttachment(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
