#include "Object.h"

Object::Object()
{
	this->Object::Object({0, 0});
}

Object::Object(FPosition p)
{
	this->Object::Object(p, "object", "¡à", "Unknown");
}

Object::Object(FPosition p, std::string name, std::string shape, std::string Type)
{
	this->Object::Object(p, name, shape, Area({1, 1}), Type);
}

Object::Object(FPosition p, std::string name, std::string shape, Area area, std::string Type)
{
	this->Object::Object(p, name, shape, area, "", Type);
}

Object::Object(FPosition p, std::string name, std::string shape, std::string direction, std::string Type)
{
	this->Object::Object(p, name, shape, Area{1, 1}, direction, Type);
}

Object::Object(FPosition p, std::string name, std::string shape, Area Area, std::string direction, std::string Type)
{
	this->name = name;
	this->shape = shape;
	this->position = p;
	this->Direction = direction;
	this->area.width = Area.width;
	this->area.height = Area.height;
	this->Type = Type;
}

std::string Object::GetName()
{
	return name;
}

void Object::SetName(std::string name)
{
	this->name = name;
}

FPosition Object::GetPosition()
{
	return position;
}

void Object::SetPosition(FPosition p)
{
	position = p;
}

std::string Object::GetShape()
{
	return shape;
}

void Object::SetShape(std::string shape)
{
	// if shape size is 1 : add " "
	this->shape = shape;
}

std::string Object::getDirection()
{
	return Direction;
}

void Object::setDirection(std::string D)
{
	this->Direction = D;
}

std::string Object::getType()
{
	return Type;
}

void Object::setType(std::string t)
{
	this->Type = t;
}

void Object::Push(std::string Direction)
{
	if (Direction == "¡è")
		Translate({0, -1});
	if (Direction == "¡ç")
		Translate({-1, 0});
	if (Direction == "¡é")
		Translate({0, +1});
	if (Direction == "¡æ")
		Translate({+1, 0});
}

void Object::Translate(FPosition p)
{
	this->position.x += p.x;
	this->position.y += p.y;
}

void Object::Translate(FPosition p, std::string shape)
{
	this->position.x += p.x;
	this->position.y += p.y;
	this->shape = shape;
}

void Object::TryWork()
{
	if (this)
		Work();
}

Area Object::GetArea()
{
	return area;
}

void Object::Work()
{
}

void Object::OnCollision(Object* other)
{
}
