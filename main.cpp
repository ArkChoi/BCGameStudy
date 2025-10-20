#include <iostream>
#include <fstream>

int main()
{
    std::ifstream Map("Level01.map");

    if (!Map.bad())
    {
        std::cout << Map.rdbuf();
        Map.close();
    }

    return 0;
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