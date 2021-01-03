#pragma once
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

class Matrix 
{
private:
	unsigned char screen[16][32];
	void wiringPi_init();
	void clk();
	void latch();
	unsigned char bits_from_int(unsigned char mode, unsigned char x);
	void set_row(unsigned char row);
	void set_color_top(unsigned char color);
	void set_color_bottom(unsigned char color);
public:
	void refresh();
	void set_pixel(unsigned char x, unsigned char y, unsigned char color);
};