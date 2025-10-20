#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	std::cout << "APlayer 持失切" << std::endl;
}

APlayer::~APlayer()
{
	std::cout << "APlayer 社瑚切" << std::endl;
}

void APlayer::Tick()
{
	AActor::Tick();
	std::cout << "APlayer Tick" << std::endl;
}