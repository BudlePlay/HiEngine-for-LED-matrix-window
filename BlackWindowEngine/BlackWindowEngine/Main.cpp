#include<vector>
#include<chrono>
#include <iomanip>

#include "EngineManager.h"
#include "TestScene.h"
#include "Matrix.h"

using namespace std;

int main()
{
    EngineManager Engine = EngineManager(new TestScene());
  
    return 0;
}