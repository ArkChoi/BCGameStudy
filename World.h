#pragma once

#include <vector>

class AActor; //전방선언 (아예 끌고 오는 것이 아닌 포인터 연결을 하기 위한 준비라고 한다..)

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void GetAllActors(std::vector<AActor*>& OutActor) const; //문제는 있다만 나중에 고친다고..
	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

	void SortActor();

protected:
	std::vector<AActor*> Actors;

};

