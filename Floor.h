#pragma once
#include "Actor.h"
class AFloor : public AActor
{
public:
	AFloor();
	virtual ~AFloor();

	class UPaperFillpbookComponent* Flipbook = nullptr;
};

