#include "TestScene.h"

#include "BasicScene.h"

TestScene::TestScene(): SceneManager()
{
	mapPointer = new Map(32, 16);
}

void TestScene::Create()
{
	worldOutliner.AddObject(new Player(FPosition({ 20, 5 }), "Player", "¡è", "Player"));
	worldOutliner.AddObject(new PushTrap(FPosition({ 15, 15 }), "PushTrap_1", "@@", "PushTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 20, 20 }), "MovingTrap_1", "HH", "¡ç", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 25, 20 }), "MovingTrap_2", "HH", "¡ç", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 28, 28 }), "MovingTrap_3", "VV", "¡è", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 28, 14 }), "MovingTrap_4", "VV", "¡è", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 22, 14 }), "MovingTrap_4", "VV", "¡è", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 25, 14 }), "MovingTrap_4", "VV", "¡è", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 2, 2 }), "MovingTrap_5", "¢È", "¡ç", "MovingTrap"));
	worldOutliner.AddObject(new MovingTrap(FPosition({ 6, 3 }), "MovingTrap_6", "¢È", "¡ç", "MovingTrap"));


	worldOutliner.AddObject(new Wall(FPosition({ 3, 4 }), "Hwall1", Area({ 10, 1 })));
	worldOutliner.AddObject(new Wall(FPosition({ 1, 10 }), "Hwall2", Area({ 15, 1 })));
	worldOutliner.AddObject(new Wall(FPosition({ 1, 20 }), "Hwall3", Area({ 10, 1 })));
	worldOutliner.AddObject(new Wall(FPosition({ 10, 2 }), "Vwall1", Area({ 1, 7 })));
	worldOutliner.AddObject(new Wall(FPosition({ 7, 8 }), "Vwall2", Area({ 1, 7 })));
	worldOutliner.AddObject(new Wall(FPosition({ 14, 10 }), "Vwall4", Area({ 2, 7 })));
	worldOutliner.AddObject(new Wall(FPosition({ 10, 8 }), "Vwall4", Area({ 1, 7 })));


	Map_Make();


	SceneChange(new BasicScene);
	
}

void TestScene::Render(float dt)
{
	/*if (Count < 0)
	{
		SceneChange(new BasicScene);
	}
	Count--;*/
	//		worldOutliner.FindObject("MovingTrap_1")->TryWork();

	//dynamic_cast<Player*>(worldOutliner.FindObject("canon1"))->getW();
}

void TestScene::Resize(int x, int y)
{
}

void TestScene::Input(float dt)
{
}

void TestScene::Pause()
{
}

TestScene::~TestScene()
{
}

void TestScene::Map_Make()
{
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Top", "¡á", Area({Size, 1}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({0, 0}), "Wall_Left", "¡á", Area({1, Size}), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({(float)Size - 1, 0}), "Wall_Right", "¡á", Area({1, Size}), "Wall"));	
	worldOutliner.AddObject(new Wall(FPosition({0, (float)15}), "Wall_Bottom", "¡á", Area({Size, 1}), "Wall"));
}

std::string TestScene::getW()
{
	return worldOutliner.FindObject("Player")->GetShape();
}
