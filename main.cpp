#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream Map("Level01.map");
    if (!Map.bad())
    {
        cout << Map.rdbuf();
        Map.close();
    }
}






//#include <iostream>
//#include "Engine.h"
//
//#include <vector>
//
//int main()
//{
//	FEngine* MyEngine;
//	MyEngine = new FEngine();
//
//	MyEngine->Init();
//	MyEngine->Run();
//	MyEngine->Term();
//
//	delete MyEngine;
//	MyEngine = nullptr;
//
//	return 0;
//}