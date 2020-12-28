#pragma once
#include <tuple>
#include <wiringPi.h>

#define R1 17
#define R2 23
#define G1 18
#define G2 24
#define B1 22
#define B2 25

#define A 7
#define B 8
#define C 9

#define CLK 3
#define LATCH 4
#define OE 2

extern unsigned char screen[16][32];