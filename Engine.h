#pragma once
class UWorld;

class FEngine
{
public: //사용자 입장의 설계
	FEngine();
	virtual ~FEngine();

	void Init(); //초기화
	void Run();  //실행
	void Term(); //종료

	__forceinline  UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return KeyCode;
	}

protected: //내부 설계
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool BIsRunning = true;

	int KeyCode = 0;
};

extern FEngine* GEngine;