#pragma once
#include "Actor.h"

class UCollsionComponent;
class UPaperFillpbookComponent;

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override;

	UCollsionComponent* Collision;
	UPaperFillpbookComponent* Flipbook;

	//Overloading
	void Jump(int a){}
	void Jump(float b){}
};

