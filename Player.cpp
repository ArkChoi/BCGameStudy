#include "Player.h"
#include <iostream>

#include "Engine.h"
#include "World.h"

#include "SDL3/SDL.h"

APlayer::APlayer()
{
	//ZOrder = 4; //이건 전적인 선택이라고 한다 , 몬스터가 올라와도 되고 , 플레이어가 올라와도 된다.
	bIsCollision = true;
	//Color = { 255,0,0,0 };

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape('P');
	Paper->SetOwner(this);
	Paper->ZOrder = 4;
	Paper->Color = {255,0,0,0};
	AddComponent(Paper);
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
	case SDLK_w:
	case SDLK_UP:
		Location.Y--;
		break;
	case  SDLK_s:
	case SDLK_DOWN:
		Location.Y++;
		break;
	case  SDLK_a:
	case SDLK_LEFT:
		Location.X--;
		break;
	case  SDLK_d:
	case SDLK_RIGHT:
		Location.X++;
		break;
	case SDLK_ESCAPE:
		exit(1);
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