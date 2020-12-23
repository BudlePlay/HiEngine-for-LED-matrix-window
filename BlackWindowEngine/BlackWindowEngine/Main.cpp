#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>


#include "EngineManager.h"
#include "TestScene.h"
#include "BasicScene.h"

using namespace std;

void removeCusor()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main()
{
    removeCusor();
    EngineManager Engine = EngineManager(new TestScene());

    return 0;
}