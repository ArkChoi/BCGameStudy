#include "Timer.h"
#include "SDL3/SDL.h"

UTimer::UTimer()
{
	CurrentTime = 0;
	LastTime = 0;
	DeltaSeconds = 0;
}

UTimer::~UTimer()
{
}

void UTimer::Tick()
{
	CurrentTime = SDL_GetTicksNS();

	DeltaSeconds = (double)(CurrentTime - LastTime) / 100000000.;

	LastTime = CurrentTime;
}