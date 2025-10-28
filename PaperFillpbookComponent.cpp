#include "SceneComponent.h"
#include "PaperFillpbookComponent.h"
#include "Vector.h"
#include "Actor.h"
#include "Engine.h"

#include <iostream>
#include <Windows.h>


UPaperFillpbookComponent::UPaperFillpbookComponent()
{
}

UPaperFillpbookComponent::~UPaperFillpbookComponent()
{
}

void UPaperFillpbookComponent::Tick()
{

}

void UPaperFillpbookComponent::Render()
{
	COORD Posistion;
	Posistion.X = GetOwner()->GetActorLocation().X;
	Posistion.Y = GetOwner()->GetActorLocation().Y;

	/*SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	std::cout << Shape;*/

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	int SizeX = 80;
	int SizeY = 60;

	SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Posistion.X, (float)Posistion.Y);
	SDL_FRect DrawRect = { (float)(Posistion.X * SizeX) , (float)(Posistion.Y * SizeY) , (float)SizeX , (float)SizeY };
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}