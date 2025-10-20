#include <iostream>
#include "Engine.h"

#include <vector>

//디자인 패턴으로 단 1개만 존재하는 객체를 지정해 주는 것 이다.
class Singleton
{
protected:
	Singleton()
	{

	}

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}return Instance;
	}
	
protected:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;

int main()
{
	Singleton* S1 = Singleton::GetInstance();
	Singleton* S2 = Singleton::GetInstance();

	FEngine* MyEngine;
	MyEngine = new FEngine();

	GEngine = MyEngine;

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}