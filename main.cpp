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

#include <SDL3/SDL.h> //이런 사용 방식은 경로 지정이 되었을때만 가능하다
#include <SDL3/SDL_main.h>
#include <iostream>

#pragma comment(lib, "SDL3")

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	SDL_Event MyEvent;
	SDL_FRect Myrect;

	bool bIsRunning = true;

	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if( MyEvent.type == SDL_EVENT_QUIT )
			{
				bIsRunning = false;
			}
			//윈도우 처리
		}
		else
		{
			SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 255);
			SDL_RenderClear(MyRenderer);

			//화면 업데이트, 사각형 100개 색갈 다르게 찍기

			Myrect = {0,0,100,100};
			for (int i = 0; i < 100; i++)
			{
				Myrect = { 0,0,(float)(rand() % 640), (float)(rand() % 480) };
				SDL_SetRenderDrawColor(MyRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
				SDL_RenderDrawRect(MyRenderer, &Myrect);
			}

			SDL_RenderPresent(MyRenderer); //Render라는 붗에 그림을 그릴 것을 모아두고 한번에 그리라고 시키는 방식이다.
		}
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	return 0;
}