#include "Map.h"

Map::Map()
{
	this->Map::Map(20, 20);
}

Map::Map(int XSIZE, int YSIZE)
{
	this->XSIZE = XSIZE;
	this->YSIZE = YSIZE;
	MapInit();
}

void Map::MapInit()
{
	lastMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));
	currentMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));
}

void Map::Print()
{
	for (auto y : *currentMap)
	{
		for (auto x : y)
		{
			std::cout << x;
		}
		std::cout << "\n";
	}
}

void Map::CopyCurrentMapANDRemoveCurrentMap()
{
	*lastMap = *currentMap;
	currentMap->clear();
	currentMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));
}

std::vector<Position> Map::ModifiedMap()
{
	std::vector<Position> positions;
	for (int y = 0; y < YSIZE; y++) //¹Ù²Ù±â
	{
		for (int x = 0; x < XSIZE; x++)
		{
			if (currentMap->at(y).at(x) != lastMap->at(y).at(x))
				positions.push_back({x, y});
		}
	}

	return positions;
}

std::string Map::GetPartOfMap(Position p)
{
	return currentMap->at(p.y).at(p.x);
}

void Map::SetPartOfMap(Position p, std::string change, Area area)
{
	for (int y = p.y; y < area.height + p.y; y++)
	{
		for (int x = p.x; x < area.width + p.x; x++)
		{
			currentMap->at(y).at(x) = change;
		}
	}
}

int Map::GetYSIZE()
{
	return YSIZE;
}
