#pragma once
#include<iostream>
#include<vector>

#include "Unit.h"
#include "Map.h"
#include "SceneManager.h"
#include "Time.h"
#include "BasicScene.h"
#include "Tools.h"



class EngineManager
{
private:

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