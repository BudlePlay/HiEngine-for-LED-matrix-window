#pragma once
#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"
#include <string.h>
#include "Unit.h"
//#include "Player.h"

class PushTrap : public Object {
private:

public:
	std::string Direction;
	std::string ID;
	PushTrap();

	PushTrap(std::string name);

	PushTrap(FPosition p, std::string name, std::string shape, std::string Type);

	PushTrap(FPosition p, std::string name, std::string shape, Area area, std::string Type);

	void Create();

	void Work() // 랜더 안에서 돌아가는 Work
	;

	void OnCollision(Object* other);

	void Push(std::string w);
};