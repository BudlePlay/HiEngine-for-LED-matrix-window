#include "BasicScene.h"


#include "TestScene.h"
#include "Wall.h"

BasicScene::BasicScene(): SceneManager()
{
	mapPointer = new Map(30, 30);
}

void BasicScene::Create()
{
	worldOutliner.AddObject(new Wall(FPosition({ 0, 0 }), "Wall_Top", "бс", Area({ Size, 1 }), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({ 0, 0 }), "Wall_Left", "бс", Area({ 1, Size }), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({ (float)Size - 1, 0 }), "Wall_Right", "бс", Area({ 1, Size }), "Wall"));
	worldOutliner.AddObject(new Wall(FPosition({ 0, (float)Size - 1 }), "Wall_Bottom", "бс", Area({ Size, 1 }), "Wall"));

}

void BasicScene::Render(float dt)
{
	SceneChange(new TestScene);
}

void BasicScene::Resize(int x, int y)
{
}

void BasicScene::Input(float dt)
{
}

void BasicScene::Pause()
{
}

BasicScene::~BasicScene()
{
}
