#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::GetAllActors(std::vector<AActor*>& OutActor) const
{
	OutActor = Actors;
}

//ÆÑÅä¸® ÆÐÅÏ
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

bool UWorld::SetSimulatePhysics(const AActor* OtherActor)
{
	return false;
}

void UWorld::SortActor()
{
	for (int j = 0; j < Actors.size(); j++)
	{
		for (int i = 0; i < Actors.size(); i++)
		{
			if (Actors[j]->GetZOrder() < Actors[i]->GetZOrder())
			{
				AActor* Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;

			}
		}
	}
}
