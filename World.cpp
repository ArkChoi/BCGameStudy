#include "World.h"
#include "Actor.h"
#include "SceneComponent.h"
#include "PaperFillpbookComponent.h"

#include <algorithm>

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

//팩토리 패턴
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		for (auto Component : Actor->Components)
		{
			Component->Tick();
		}
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for (auto Component : Actor->Components)
		{
			USceneComponent* Scene = dynamic_cast<USceneComponent*>(Component);
			if (Scene)
			{
				Scene->Render();
			}
		}
		//Actor->Render();
	}
}

bool UWorld::SetSimulatePhysics(const AActor* OtherActor)
{
	return false;
}

void UWorld::SortActor()
{
	//람다함수, 캡쳐절?
	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B)
		{
			UPaperFillpbookComponent* Scene1 = nullptr;
			for (auto Component : A->Components)
			{
				Scene1 = dynamic_cast<UPaperFillpbookComponent*>(Component);
				if (Scene1)
				{
					break;
				}
			}

			UPaperFillpbookComponent* Scene2 = nullptr;
			for (auto Component : B->Components)
			{
				Scene2 = dynamic_cast<UPaperFillpbookComponent*>(Component);
				if (Scene2)
				{
					break;
				}
			}

			if (!Scene1 || !Scene2)
			{
				return false;
			}

			return (Scene1->GetZOrder() < Scene2->GetZOrder());
		});

	//이 밑에 로직좀 이해해야한다.
	//for (int j = 0; j < Actors.size(); ++j)
	//{
	//	//선택한 액터
	//	UPaperFillpbookComponent* Scene1 = nullptr;
	//	for (auto Component : Actors[j]->Components)
	//	{
	//		Scene1 = dynamic_cast<UPaperFillpbookComponent*>(Component);
	//		if (Scene1)
	//		{
	//			break;
	//		}
	//	}

	//	if (!Scene1)
	//	{
	//		continue;
	//	}

	//	for (int i = 0; i < Actors.size(); ++i)
	//	{
	//		UPaperFillpbookComponent* Scene2 = nullptr;
	//		for (auto Component : Actors[i]->Components)
	//		{
	//			Scene2 = dynamic_cast<UPaperFillpbookComponent*>(Component);
	//			if (Scene2)
	//			{
	//				break;
	//			}
	//		}

	//		if (!Scene2)
	//		{
	//			continue;
	//		}


	//		if (Scene1->GetZOrder() < Scene2->GetZOrder())
	//		{
	//			AActor* Temp = Actors[j];
	//			Actors[j] = Actors[i];
	//			Actors[i] = Temp;
	//		}
	//	}
	//}
}
