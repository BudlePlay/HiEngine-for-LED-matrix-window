#include "PushTrap.h"

PushTrap::PushTrap()
{
}

PushTrap::PushTrap(std::string name)
{
	ID = name;
}

PushTrap::PushTrap(FPosition p, std::string name, std::string shape, std::string Type): Object(p, name, shape, Type)
{
	ID = name;
}

PushTrap::PushTrap(FPosition p, std::string name, std::string shape, Area area, std::string Type): Object(
	p, name, shape, area, Type)
{
	ID = name;
}

void PushTrap::Create()
{
}

void PushTrap::Work()
{
}

void PushTrap::OnCollision(Object* other)
{
	std::string Direction;
	static std::string back;

	Object* o = WorldOutliner::FindObject("Player");
	//Direction = o->GetShape();
	Object* Pushtrap = WorldOutliner::FindObject(ID);

	if (other->getType() == "Player")
	{
		Direction = o->GetShape();

		if (Direction == "ก่")
		{
			Translate({0, -1});
			back = Direction;
		}
		if (Direction == "ก็")
		{
			Translate({-1, 0});
			back = Direction;
		}
		if (Direction == "ก้")
		{
			Translate({0, +1});
			back = Direction;
		}
		if (Direction == "กๆ")
		{
			Translate({+1, 0});
			back = Direction;
		}
	}
	else if (other->getType() == "Wall")
	{
		FPosition object_Position = o->GetPosition();
		FPosition Pushtrap_Position = Pushtrap->GetPosition();
		Direction = o->GetShape();
		if (back == "ก่")
		{
			Translate({0, +1});
			o->Translate({0, +1});
		}
		if (back == "ก็")
		{
			Translate({+1, 0});
			o->Translate({+1, 0});
		}
		if (back == "ก้")
		{
			Translate({0, -1});
			o->Translate({0, -1});
		}
		if (back == "กๆ")
		{
			Translate({-1, 0});
			o->Translate({-1, 0});
		}
	}
}

void PushTrap::Push(std::string w)
{
}
