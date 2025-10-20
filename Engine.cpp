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
                       
                {
                    AActor* NewActor = new AWall();
                    NewActor->SetActorLocation(FVector2D(X, Y));
                    NewActor->SetShape(' ');
                    World->SpawnActor(NewActor);
                }
            }
            Y++;
            std::cout << std::endl;
        }
    }

    std::sort(World->GetAllActors(), World->GetAllActors().end(), std::greater<AActor*>()); //vector<AActor*>

    MapFile.close();

    std::cout << GetWorld()->GetAllActors().size() << std::endl;
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

void FEngine::Sort()
{
    int Max = GetWorld()->GetAllActors().size();
    AActor* TempActors[Max];
}

void FEngine::Swap(AActor* FirstIndex, AActor* SecondIndex)
{
    AActor* Temp;

    Temp = FirstIndex;
    FirstIndex = SecondIndex;
    SecondIndex = Temp;
}
