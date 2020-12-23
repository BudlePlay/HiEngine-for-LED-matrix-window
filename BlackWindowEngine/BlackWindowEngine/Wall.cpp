#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(FPosition p, std::string name, Area area): Object(p, name, "бс", area, "Wall")
{
}

Wall::Wall(FPosition p, std::string name, std::string shape, std::string Type): Object(p, name, shape, Type)
{
}

Wall::Wall(FPosition p, std::string name, std::string shape, Area area, std::string Type): Object(
	p, name, shape, area, Type)
{
}

void Wall::Work()
{
	Make();
}

void Wall::Make()
{
}

void Wall::OnCollision(Object* other)
{
}

void Wall::Pause()
{
}

Wall::~Wall()
{
}
