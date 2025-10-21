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

FEngine* FEngine::Instance = nullptr;

//UECode
//FEngine* GEngine = nullptr;

FEngine::FEngine()
{
    World = nullptr;
}

FEngine::~FEngine()
{

}

void FEngine::Init()
{
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
                    AActor* NewActor = new AWall();
                    NewActor->SetActorLocation(FVector2D(X, Y));
                    NewActor->SetShape(' ');
                    World->SpawnActor(NewActor);
                }

                if(Line[X]=='*')
                {
                    AActor* NewActor = new AWall();
                    NewActor->SetActorLocation(FVector2D(X,Y));
                    NewActor->SetShape('*');
                    World->SpawnActor(NewActor);
                }
                else if (Line[X] == 'P')
                {
                    AActor* NewActor = new APlayer();
                    NewActor->SetActorLocation(FVector2D(X, Y));
                    NewActor->SetShape('P');
                    World->SpawnActor(NewActor);
                }
                else if (Line[X] == 'M')
                {
                    AActor* NewActor = new AMonster();
                    NewActor->SetActorLocation(FVector2D(X, Y));
                    NewActor->SetShape('M');
                    World->SpawnActor(NewActor);
                }
                else if (Line[X] == 'G')
                {
                    AActor* NewActor = new AGoal();
                    NewActor->SetActorLocation(FVector2D(X, Y));
                    NewActor->SetShape('G');
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
}

void FEngine::Run()
{
	while (BIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{

}

void FEngine::Input()
{
    KeyCode = _getch();
}

void FEngine::Tick()
{
    GetWorld()->Tick();
}

void FEngine::Render()
{
    GetWorld()->Render();
}
