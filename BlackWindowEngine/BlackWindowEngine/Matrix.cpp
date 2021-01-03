#include "Matrix.h"

void Matrix::wiringPi_init() {
	wiringPiSetupGpio();

	pinMode(R1, OUTPUT);
	pinMode(R2, OUTPUT);
	pinMode(G1, OUTPUT);
	pinMode(G2, OUTPUT);
	pinMode(B1, OUTPUT);
	pinMode(B2, OUTPUT);

	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);

	pinMode(CLK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	pinMode(OE, OUTPUT);
}
void Matrix::clk() {
	digitalWrite(CLK, 1);
	delayMicroseconds(10);
	digitalWrite(CLK, 0);
}
void Matrix::latch() {
	digitalWrite(LATCH, 1);
	delayMicroseconds(10);
	digitalWrite(LATCH, 0);
}
unsigned char Matrix::bits_from_int(unsigned char mode, unsigned char x) {
	if (mode == 0) return x & 1;
	else if (mode == 1) return x & 2;
	else return x & 4
}
void Matrix::set_row(unsigned char row) {
	digitalWrite(A, bits_from_int(0, row));
	digitalWrite(B, bits_from_int(1, row));
	digitalWrite(C, bits_from_int(2, row));
}
void Matrix::set_color_top(unsigned char color) {
	digitalWrite(R1, bits_from_int(0, color));
	digitalWrite(G1, bits_from_int(1, color));
	digitalWrite(B1, bits_from_int(2, color));
}
void Matrix::set_color_bottom(unsigned char color) {
	digitalWrite(R2, bits_from_int(0, color));
	digitalWrite(G2, bits_from_int(1, color));
	digitalWrite(B2, bits_from_int(2, color));
}
void Matrix::refresh() {
	for (int row = 0; row < 8; row++) {
		digitalWrite(OE, 1);
		set_color_top(0);
		set_row(row);
		for (int col = 0; col < 32; col++) {
			set_color_top(screen[row][col]);
			set_color_bottom(screen[row + 8][col]);
			clk();
		}
		latch();
		digitalWrite(OE, 0);
		delay(1);
	}
}
void Matrix::set_pixel(unsigned char x, unsigned char y, unsigned char color) {
	screen[y][x] = color;
}