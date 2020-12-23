#pragma once
#include <Windows.h>


class Time
{
private:
	LARGE_INTEGER start, end, f;
	unsigned int fps = 0;
	float elapsed_time = 0;
public:
	float deltaTime = 0;

	Time();

	void StartMeasure();

	void EndMeasure();
};