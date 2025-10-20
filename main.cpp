#include <iostream>
#include "Actor.h"
#include "Player.h"

#include <vector>

int main()
{
	std::vector<AActor*> Actors;
	Actors.push_back(new AActor());
	Actors.push_back(new APlayer());

	for (auto Data : Actors)
	{
		Data->Tick();
	}

	for (int i = 0 ; i < Actors.size() ; i++)
	{
		delete Actors[i];
	}
	Actors.clear();

	return 0;
}