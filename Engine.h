#pragma once
class FEngine
{
public: //사용자 입장의 설계
	FEngine();
	virtual ~FEngine();

	void Init(); //초기화
	void Run();  //실행
	void Term(); //종료

protected: //내부 설계
	void Input();
	void Tick();
	void Render();

	bool BIsRunning = true;
};

