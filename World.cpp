#include "World.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	return nullptr;
}
