#include "Unit.h"

Position PositionTools::FPtoIP(FPosition fp)
{
	return Position{(int)(fp.x), (int)(fp.y)};
}

bool PositionTools::IsEqual(FPosition m, FPosition o)
{
	Position me = FPtoIP(m);
	Position other = FPtoIP(o);

	if ((me.x == other.x) && (me.y == other.y))
		return true;
	else
		return false;
}
