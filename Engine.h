#pragma once
#include <SDL3/SDL.h>
#pragma comment(lib, "SDL3")

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
	void OpenLevel();

	__forceinline  UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return KeyCode;
	}

	//편의성 때문에 퍼블릭임
	SDL_Window* MyWindow;
	//편의성 때문에 퍼블릭임
	SDL_Renderer* MyRenderer;
	//편의성 때문에 퍼블릭임
	SDL_Event MyEvent;

protected: //내부 설계
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool BIsRunning = true;

	int KeyCode = 0;

	static FEngine* Instance;

};


//실제 엔진 코드라고..
//extern FEngine* GEngine;
#define GEngine		FEngine::GetInstance()