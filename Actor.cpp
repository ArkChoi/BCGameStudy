#include "Actor.h"
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
}

//void AActor::SetSimulatePhysics()
//{
//}

bool AActor::CheakCollsion(const AActor* OtherActor)
{
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
