#include "SceneComponent.h"
#include "PaperFillpbookComponent.h"
#include "Vector.h"
#include "Actor.h"
#include "Engine.h"

#include <iostream>
#include <Windows.h>
#include "SDL3/SDL.h"


UPaperFillpbookComponent::UPaperFillpbookComponent()
{
}

UPaperFillpbookComponent::~UPaperFillpbookComponent()
{
	if (BitmapImage)
	{
		SDL_DestroySurface(BitmapImage);
		BitmapImage = nullptr;
	}
	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
}

void UPaperFillpbookComponent::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();
	if (TotalTime < ExecuteTime)
	{
		return;
	}

	TotalTime = 0.f;
	if (bAnimation)
	{
		XIndex++;
		XIndex = (float)((int)XIndex % (int)SpriteCountX);
		// 잘 안나오니 사용한 함수
		// SDL_Log("Index X : %f",&XIndex);
	}
}

void UPaperFillpbookComponent::Render()
{
	COORD Posistion;
	Posistion.X = GetOwner()->GetActorLocation().X;
	Posistion.Y = GetOwner()->GetActorLocation().Y;
	int SizeX = 80;
	int SizeY = 60;

	/*SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	std::cout << Shape;*/
	if (!BitmapImage && !Texture)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);

		SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Posistion.X, (float)Posistion.Y);
		SDL_FRect DrawRect = { (float)(Posistion.X * SizeX) , (float)(Posistion.Y * SizeY) , (float)SizeX , (float)SizeY };
		SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
	}
	else
	{
		SDL_FRect SourceRect;
		if (bAnimation)
		{
			int SpirteSizeX = BitmapImage->w / SpriteCountX;
			int SpirteSizeY = BitmapImage->h / SpriteCountY;
			SourceRect = { 
				XIndex * SpirteSizeX ,
				YIndex * SpirteSizeY ,
				(float)SpirteSizeX ,
				(float)SpirteSizeY
			};
		}
		else
		{
			SourceRect = { 0,0,(float)BitmapImage->w,(float)BitmapImage->h };
		}

		SDL_FRect DestinationRect = { 
			(float)(Posistion.X * SizeX),
			(float)(Posistion.Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestinationRect);
	}
}

void UPaperFillpbookComponent::LoadBMP(std::string Filename)
{
	// 왜 2개 거쳐가요? CPU->Memory->GPU 이방식이어야 함 Apple은 그래서 CPU->Memory<-GPU 구조로 만듬
	BitmapImage = SDL_LoadBMP(Filename.c_str()); //원본 이미지 (압축된 이미지를 푸는 것)

	SDL_SetColorKey(BitmapImage, true, 
		SDL_MapRGBA(
			SDL_GetPixelFormatDetails(BitmapImage->format),
			nullptr,
			ColorKey.r,
			ColorKey.g,
			ColorKey.b,
			ColorKey.a)
	);

	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer , BitmapImage); //메모리로 넘길 친구 복사하기
}
