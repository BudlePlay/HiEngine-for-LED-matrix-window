#pragma once


struct Position
{
	int x;
	int y;
};

struct FPosition
{
	float x;
	float y;
};

struct Area
{
	int width;
	int height;
};
class PositionTools
{
public:
	static Position FPtoIP(FPosition fp);

	static bool IsEqual(FPosition m, FPosition o);
};