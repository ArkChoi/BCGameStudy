#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override;

	//Overloading
	void Jump(int a){}
	void Jump(float b){}

};

