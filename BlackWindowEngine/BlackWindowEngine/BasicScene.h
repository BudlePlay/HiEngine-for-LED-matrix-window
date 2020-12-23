#pragma once

#include "SceneManager.h"


using namespace std;

class BasicScene : public SceneManager
{
public:
	int Size = 30;
	BasicScene();

	void Create();

	void Render(float dt);

	void Resize(int x, int y);

	void Input(float dt);

	void Pause();

	~BasicScene();
};