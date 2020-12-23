#pragma once

#include "Object.h"

class Wall : public Object {
private:

public:
	
	//WorldOutliner worldOutliner;
	Wall();

	Wall(FPosition p, std::string name, Area area);

	Wall(FPosition p, std::string name, std::string shape, std::string Type);

	Wall(FPosition p, std::string name, std::string shape, Area area, std::string Type);

	void Work() // 랜더 안에서 돌아가는 Work
	;

	void Make();

	void OnCollision(Object* other);


	void Pause();

	~Wall();
};