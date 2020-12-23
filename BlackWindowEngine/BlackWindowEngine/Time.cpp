#include "Time.h"

Time::Time()
{
}

void Time::StartMeasure()
{
	fps++;
	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&start);
}

void Time::EndMeasure()
{
	elapsed_time += deltaTime;
	Sleep(10); // if delta time -> 0    time goes slowly
	QueryPerformanceCounter(&end);
	deltaTime = (end.QuadPart - start.QuadPart) / (float)f.QuadPart;
}
