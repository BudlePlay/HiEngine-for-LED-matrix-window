#pragma once

#include "Canon.h"
#include "SceneManager.h"
#include <optional>
#include "Player.h"
#include "Wall.h"
#include "PushTrap.h"
#include "MovingTrap.h"

class TestScene : public SceneManager
{
private:
public:
	int Count = 100;
	int Size = 32;
	TestScene();;
	void Create();

	void Render(float dt);

	void Resize(int x, int y);

	void Input(float dt);

	void Pause();

	~TestScene();

	void Map_Make();

	std::string getW();
};