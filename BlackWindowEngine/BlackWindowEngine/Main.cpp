#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>

#include "SerialClass.h"
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
    Serial* ser = new Serial("");
    char message[1000];

    if (ser->IsConnected()) {
        cout << "Serial Communication Connected." << endl;
        // memset(message, 0, sizeof(message));
        // Serial::ReadData() 내부에서 memset이 실행된다.
        ser->ReadData(message, sizeof(message));
        cout << "Message from Arduino: " << message << endl;
    }
    else {
        cout << "Device can not be found or can not be configured." << endl;
        return 0;
    }

    while (1) {
        cout << "Choose : ";
        cin >> message;

        if (!strcmp(message, "q") || !strcmp(message, "Q")) {
            break;
        }
        //		else if (!strcmp(message, "0")) {            
        //            ser->WriteData("0", 1);
        //            Sleep(200); // 아두이노와의 시리얼 통신을 위한 대기 시간.            
        //            ser->ReadData(message, sizeof(message));
        //            cout << "Message from Arduino: " << message << endl;
        //        } else {
        //            ser->WriteData("1", 1);
        //            Sleep(200); // 아두이노와의 시리얼 통신을 위한 대기 시간.            
        //            ser->ReadData(message, sizeof(message));
        //            cout << "Message from Arduino: " << message << endl;
        //        }
        ser->WriteData(message, strlen(message) + 1);
        ser->ReadData(message, sizeof(message));
        cout << "Message from Arduino: " << message << endl;
    }
    /*removeCusor();
    EngineManager Engine = EngineManager(new TestScene());*/

    return 0;
}