#include <iostream>

#include "Monster.h"
#include "Engine.h"
#include "World.h"

#include "PaperFillpbookComponent.h"

AMonster::AMonster()
{
	//ZOrder = 3;
	bIsCollision = true;
	//Color = {0,0,255,0};

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape('M');
	Paper->SetOwner(this);
	Paper->ZOrder = 3;
	Paper->Color = { 0,0,255,0 };
	AddComponent(Paper);
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
		if (CheakCollsion(OtherActor))
		{
			bFlag = true;
			break;
		}
	}
	if (bFlag)
	{
		Location = SaveLocation;
	}
}