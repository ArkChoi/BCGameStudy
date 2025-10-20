#include "Engine.h"

FEngine::FEngine()
{

}

FEngine::~FEngine()
{

}

void FEngine::Init()
{

}

void FEngine::Run()
{
	while (BIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{

}

void FEngine::Input()
{

}

void FEngine::Tick()
{

}

void FEngine::Render()
{

}