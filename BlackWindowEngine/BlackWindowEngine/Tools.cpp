#include "Tools.h"

void Tools::cersorMoveTo(Position p)
{
	COORD position = {(short)p.x * 2, (short)p.y};
	static HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);
}

void Tools::backCusor()
{
	cersorMoveTo({0, 0});
}
