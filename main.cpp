#include <iostream>
#include "Actor.h"

int main()
{
	AActor* Actor;
	Actor = new AActor;

	Actor->Tick();

	delete Actor;

	return 0;
}