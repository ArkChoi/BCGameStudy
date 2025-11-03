#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	virtual ~AGoal();

	class UPaperFillpbookComponent* Flipbook = nullptr;
};

