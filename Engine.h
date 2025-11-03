#pragma once
#include <SDL3/SDL.h>
#include "Input.h"
#pragma comment(lib, "SDL3")

#include <string>

class UWorld;
class AActor;

class FEngine
{
protected:
	FEngine();

public: //사용자 입장의 설계
	virtual ~FEngine();

	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

	void Init(); //초기화
	void Run();  //실행
	void Term(); //종료
	void OpenLevel(std::string LevelName);

	__forceinline  UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return UInput::KeyCode;
	}

	//편의성 때문에 퍼블릭임
	SDL_Window* MyWindow;
	//편의성 때문에 퍼블릭임
	SDL_Renderer* MyRenderer;
	//편의성 때문에 퍼블릭임
	SDL_Event MyEvent;

	double GetWorldDeltaSeconds();

protected: //내부 설계
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool BIsRunning = true;

	//int KeyCode = 0;

	static FEngine* Instance;

	SDL_Time DeltaSeconds;

	class UTimer* Timer = nullptr;
	class UInput* InputDevice = nullptr;

};


//실제 엔진 코드라고..
//extern FEngine* GEngine;
#define GEngine		FEngine::GetInstance()