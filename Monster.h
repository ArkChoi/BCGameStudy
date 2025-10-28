#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;

	float ExecuteTime = 0.5f;
	float TotalTime = 0.0f;
};

