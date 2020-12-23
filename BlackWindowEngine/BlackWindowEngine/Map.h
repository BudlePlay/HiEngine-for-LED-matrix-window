#pragma once

#include<iostream>
#include<vector>

#include "Unit.h"

class Map
{

private:
	int XSIZE;
	int YSIZE;
public:

	std::vector<std::vector<std::string>>* lastMap;
	std::vector<std::vector<std::string>>* currentMap;

	Map();

	Map(int XSIZE, int YSIZE);

	void MapInit();

	void Print();

	void CopyCurrentMapANDRemoveCurrentMap();

	std::vector<Position> ModifiedMap();


	std::string GetPartOfMap(Position p);

	void SetPartOfMap(Position p, std::string change, Area area);

	int GetYSIZE();
};
