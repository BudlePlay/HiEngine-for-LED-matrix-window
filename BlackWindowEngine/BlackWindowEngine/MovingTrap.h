#pragma once
#include "Object.h"
#include "WorldOutliner.h"


class MovingTrap : public Object {
private:
	
public:
	std::string Direction;
	std::string ID;
	MovingTrap();

	MovingTrap(FPosition Position, std::string Name, std::string Shape, std::string Direction, std::string Type);


	void Work();

	/*void OnCollision(Object* other) 
	{
		Object* o = WorldOutliner::FindObject(ID);
		if (o->getDirection() == "ก่") {
			o->setDirection("ก้");
		}
		if (o->getDirection() == "ก้") {
			o->setDirection("ก่");
		}

		if (o->getDirection() == "ก็") {
			Translate({ +5, 0 });
			o->setDirection("กๆ");
			
		}
		if (o->getDirection() == "กๆ") {
			o->setDirection("ก็");
		}
	}*/

	void OnCollision(Object* other);

	void Move();
};