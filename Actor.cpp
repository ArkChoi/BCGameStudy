#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>

AActor::AActor() : ZOrder(0), Shape(' ')
{

}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Posistion;
	Posistion.X = Location.X;
	Posistion.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	std::cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	int SizeX = 80;
	int SizeY = 60;
	
	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRect = { (float)(Location.X * SizeX) , (float)(Location.Y * SizeY) , (float)SizeX , (float)SizeY };
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}

//void AActor::SetSimulatePhysics()
//{
//}

bool AActor::CheakCollsion(const AActor* OtherActor)
{
	if (OtherActor->bIsOverlap)
	{
		return false;
	}

	if (this != OtherActor && OtherActor->bIsCollision && bIsCollision
		&& this->Location == OtherActor->Location)
	{
		return true;
	}
	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}
