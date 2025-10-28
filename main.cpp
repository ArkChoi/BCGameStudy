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
#define SDL_ENABLE_OLD_NAMES

#include <SDL3/SDL_main.h>
#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	SDL_Time Timer = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	Timer = SDL_GetTicks64() - Timer;
	return 0;
}