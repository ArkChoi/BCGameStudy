#include "Player.h"
#include <iostream>

#include "Engine.h"
#include "World.h"

#include "CollsionComponent.h"
#include "PaperFillpbookComponent.h"

#include "SDL3/SDL.h"

APlayer::APlayer()
{
	//ZOrder = 4; //이건 전적인 선택이라고 한다 , 몬스터가 올라와도 되고 , 플레이어가 올라와도 된다.
	//bIsCollision = true;
	//Color = { 255,0,0,0 };

	Collision = new UCollsionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);

	Flipbook = new UPaperFillpbookComponent();
	Flipbook->SetShape('P');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 4;
	Flipbook->Color = {255,0,0,0};
	SetupAttachment(Flipbook);
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
		Flipbook->YIndex = 2;
		break;
	case  SDLK_s:
	case SDLK_DOWN:
		Location.Y++;
		Flipbook->YIndex = 3;
		break;
	case  SDLK_a:
	case SDLK_LEFT:
		Location.X--;
		Flipbook->YIndex = 0;
		break;
	case  SDLK_d:
	case SDLK_RIGHT:
		Location.X++;
		Flipbook->YIndex = 1;
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