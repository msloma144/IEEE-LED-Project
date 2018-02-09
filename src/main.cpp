#include <FastLED.h>
#include "letters.h"
#include <string>
#include <iostream>

#define LED_PIN     5
#define NUM_LEDS    30
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define LINE_LENGTH 30
#define UPDATES_PER_SECOND 100
unsigned int count;
CRGB *leds;
std::vector<std::vector<CRGB>> colorMatrix;


// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    Serial.begin(9600);
    Serial.print("Starting...");

    delay( 3000 ); // power-up safety delay
    count = 0;
    std::string input = "test";

    colorMatrix = stringtoColor(input, LINE_LENGTH, NUM_LEDS);
    leds = slideView(colorMatrix, LINE_LENGTH, count);

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void loop() {
  Serial.print("Looping...");;

  if(count > LINE_LENGTH){
    count = 0;
  }
  leds = slideView(colorMatrix, LINE_LENGTH, count);
  FastLED.show();
}
