#pragma once
#include<iostream>
#include<vector>

#include "Unit.h"
#include "Map.h"
#include "SceneManager.h"
#include "Time.h"
#include "BasicScene.h"
#include "Tools.h"

#include "SerialClass.h"


class EngineManager
{
private:
	Serial* ser;
	char message[1000];
	Time time;
	SceneManager* scene;
public:
	EngineManager();

	EngineManager(SceneManager* scene);

	void Game();

	void BoomCheck();

	void Work();

	void Print_Map();

	~EngineManager();
};