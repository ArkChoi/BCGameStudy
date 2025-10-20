#include "Player.h"
#include <iostream>

#include "Engine.h"

APlayer::APlayer()
{
	ZOrder = 4; //이건 전적인 선택이라고 한다 , 몬스터가 올라와도 되고 , 플레이어가 올라와도 된다.
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int GetKeyCode = GEngine->GetKeyCode();

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
}