#pragma once

#include "WorldOutliner.h"
#include "Object.h"
#include "MovingTrap.h"
class Canon : public Object
{
private:
	bool ch = true;
	std::string Direction;
	float speed = 0.7;
public:
	
	std::string shape2;
	Canon(FPosition p, std::string name, std::string shape, std::string shape2, Area area, std::string Direction,
	      std::string Type);

	virtual void Work();

	void Move(std::string D);

	void SwapShape();

	void DoNothing();

	virtual void OnCollision(Object* other);
};