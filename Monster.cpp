#include <iostream>

#include "Monster.h"
#include "Engine.h"
#include "World.h"

#include "PaperFillpbookComponent.h"
#include "CollsionComponent.h"

AMonster::AMonster()
{
	//ZOrder = 3;
	//bIsCollision = true;
	//Color = {0,0,255,0};

	Collision = new UCollsionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);

	Flipbook = new UPaperFillpbookComponent();
	Flipbook->SetShape('M');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 3;
	Flipbook->Color = { 0,0,255,0 };
	SetupAttachment(Flipbook);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();
	if (TotalTime < ExecuteTime)
	{
		return;
	}

	TotalTime = 0.f;

	int GetKeyCode = rand()%4;
	FVector2D SaveLocation;
	SaveLocation = Location;

	switch (GetKeyCode)
	{
	case 0:
		Location.Y--;
		break;
	case 1:
		Location.Y++;
		break;
	case 2:
		Location.X--;
		break;
	case 3:
		Location.X++;
		break;
	default:
		break;
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;
	for (auto OtherActor : AllActors)
	{
		for (auto Components : OtherActor->Components)
		{
			UCollsionComponent* OtherCollision = dynamic_cast<UCollsionComponent*>(Components);
			if (OtherCollision)
			{
				if (Collision->CheakCollsion(OtherCollision))
				{
					bFlag = true;
					break;
				}
			}
		}
	}
	if (bFlag)
	{
		Location = SaveLocation;
	}
}