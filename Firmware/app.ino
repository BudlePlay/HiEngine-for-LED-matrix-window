// testcolors demo for Adafruit RGBmatrixPanel library.
// Renders 512 colors on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420
// Library supports 4096 colors, but there aren't that many pixels!  :)

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK 8 // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
unsigned char buff[6], buff_cnt;

void setup()
{
  Serial.begin(9600);
  matrix.begin();
}
void reset()
{
  for (int i = 0; i < 32; i++)
  {
    for (int j = 0; j < 16; j++)
    {
      matrix.drawPixel(i, j, matrix.Color333(0, 0, 0));
    }
  }
  Serial.print("reset");
  Serial.flush();
  buff_cnt = 0;
}
void loop()
{
  if (Serial.available() > 0)
  {
    buff[buff_cnt++] = Serial.read() - '0';
    if (buff_cnt > 5)
    {
      if (buff[4])
        matrix.drawPixel(buff[0] * 10 + buff[1], buff[2] * 10 + buff[3], matrix.Color333(7, 7, 7));
      else
        matrix.drawPixel(buff[0] * 10 + buff[1], buff[2] * 10 + buff[3], matrix.Color333(0, 0, 0));
      buff_cnt = 0;
    }
  }
}