#include "Player.h"
#include <iostream>

#include "Engine.h"
#include "World.h"

APlayer::APlayer()
{
	ZOrder = 4; //이건 전적인 선택이라고 한다 , 몬스터가 올라와도 되고 , 플레이어가 올라와도 된다.
	bIsCollision = true;
	Color = { 255,0,0,0 };
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int GetKeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;

	switch (GetKeyCode)
	{
	case 'w':
		Location.Y--;
		break;
	case 's':
		Location.Y++;
		break;
	case 'a':
		Location.X--;
		break;
	case 'd':
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