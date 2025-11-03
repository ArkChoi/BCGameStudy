#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <vector>

#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"
#include "Wall.h"
#include "GameMode.h"
#include "Timer.h"
#include "Input.h"
#include "PaperFillpbookComponent.h"

#pragma comment(lib, "SDL3")

FEngine* FEngine::Instance = nullptr;

//UECode
//FEngine* GEngine = nullptr;

FEngine::FEngine()
{
	World = nullptr;
	Timer = new UTimer();
	InputDevice = new UInput();
}

FEngine::~FEngine()
{
	if (World)
	{
		delete World;
	}
	if (Timer)
	{
		delete Timer;
	}
	if (InputDevice)
	{
		delete InputDevice;
	}
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO);

	MyWindow = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
}

void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));

	World = new UWorld;
	std::ifstream MapFile("Level01.map");

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 255))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); X++)
			{
				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFillpbookComponent>()->LoadBMP("./Data/floor.bmp");
					//NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}

				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFillpbookComponent>()->LoadBMP("./Data/wall.bmp");
					//NewActor->SetShape('*');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFillpbookComponent>()->LoadBMP("./Data/Player.bmp");
					//NewActor->SetShape('P');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFillpbookComponent>()->LoadBMP("./Data/Slime.bmp");
					//NewActor->SetShape('M');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFillpbookComponent>()->LoadBMP("./Data/Goal.bmp");
					//NewActor->SetShape('G');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
			std::cout << std::endl;
		}
	}
	GetWorld()->SortActor();

	MapFile.close();

	std::vector<AActor*> Temp;
	GetWorld()->GetAllActors(Temp);
	std::cout << Temp.size() << std::endl;

	//UE Gameplay Framework
	World->SpawnActor(new AGameMode());
}

void FEngine::Run()
{
	while (BIsRunning)
	{
		Timer->Tick();

		if (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_QUIT:
				BIsRunning = false;
			default:
				break;
			}
		}

		Input(); 
		Tick();
		Render();
	}
}

void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

double FEngine::GetWorldDeltaSeconds()
{
	return Timer->DeltaSeconds;
}

void FEngine::Input()
{
	InputDevice->Tick();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}
