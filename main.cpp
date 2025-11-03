//#include <iostream>
//#include <vector>
//#include <list>
//
//#include "Engine.h"
//#include "DynamicArray.h"
//
//int main()
//{
//	GEngine->Init();
//	GEngine->Run();
//	GEngine->Term();
//
//	delete GEngine;
//
//	return 0;
//}

//#include <iostream>

//c++ console entry -> ios, window, linux

#include <SDL3/SDL_main.h>
#include "Engine.h"

class Animal
{
public:
	void Eat(){}
};

class Plant
{
public:
	void Eat(){}
};

int SDL_main(int argc, char* argv[])
{
	SDL_Time deltaSeconds = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	deltaSeconds = SDL_GetTicks64() - deltaSeconds;
	return 0;
}