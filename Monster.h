#pragma once
#include "Actor.h"

class UCollsionComponent;
class UPaperFillpbookComponent;

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;

	float ExecuteTime = 0.5f;
	float TotalTime = 0.0f;

	UCollsionComponent* Collision;
	UPaperFillpbookComponent* Flipbook;
};

