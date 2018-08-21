#include <iostream>
#include "letters.h"
#include <FastLED.h>

using namespace std;

void scroll(int line_width, int num_lines, int max_length, bool output[]){
    int max_iter = 10000;
    int i = 0;
    int start = 0;
    int end = line_width;
    bool *window = new bool[num_lines * line_width];

    while (i < max_iter) {
        int index = 0;

        for (int j = 0; j < num_lines; j++) {
            if(start < end) {
                for (int k = start; k < end; k++) {
                    int get_index = k + (j * max_length);
                    window[index] = output[get_index];
                    index++;
                }
            }
            else{
                for (int k = start; k < max_length; k++) {
                    int get_index = k + (j * max_length);
                    window[index] = output[get_index];
                    index++;
                }

                for (int k = 0; k <= end; k++) {
                    int get_index = k + (j * max_length);
                    window[index] = output[get_index];
                    index++;
                }
            }
        }

        // print window
        for (int ii = 0; ii < num_lines; ii++) {
            int line_start_val = ii * line_width;
            for (int j = line_start_val; j < line_start_val + line_width; j++) {
                if (j % line_width == 0 and j != 0) {
                }
            }
        }


        if(start < max_length)
            start++;
        else
            start = 0;

        if(end < max_length)
            end++;
        else
            end = 0;

        delay(1000);
        i++;
    }
}


int main() {
    char word[] = "A B A A A";

    int num_leds = 100;
    int num_lines = 5;
    int line_width = num_leds / num_lines;


    int max_length = 0;
    int curr_length = 0;
    int content_length = 0;

    int line_pos;
    int matrix_size;
    bool *output;

    // get content width
    for (char letter : word) {
        content_length += getLetterLength(letter);
    }

    matrix_size = (content_length + line_width) * num_lines;
    output = new bool[matrix_size];

    // build matrix
    for (int i = 0; i < num_lines; i++) {
        line_pos = 0;

        // fills line with letters
        for (char letter : word) {
            bool *x = getLetterArray(letter, i);
            int letter_len = getLetterLength(letter);

            for (int j = 0; j < letter_len; j++) {
                output[curr_length] = x[j];
                curr_length++;
                line_pos++;

                if (i == 0) {
                    max_length++;
                }
            }
        }

        // fill end with spaces to allow for blank screen between rotations
        if (line_pos < (content_length + line_width)) {
            for (int j = line_pos; j < (content_length + line_width); j++) {
                output[curr_length] = 0;
                curr_length++;

                if (i == 0) {
                    max_length++;
                }
            }
        }
    }

    scroll(line_width, num_lines, max_length, output);

    return 0;
}



#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

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

// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.


// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette()
{
    for( int i = 0; i < 16; i++) {
        currentPalette[i] = CHSV( random8(), 255, random8());
    }
}

// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.
void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[8] = CRGB::White;
    currentPalette[12] = CRGB::White;

}

// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;

    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}


// This example shows how to set up a static color palette
// which is stored in PROGMEM (flash), which is almost always more
// plentiful than RAM.  A static PROGMEM palette like this
// takes up 64 bytes of flash.
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,
    CRGB::Gray, // 'white' is too bright compared to red and blue
    CRGB::Blue,
    CRGB::Black,

    CRGB::Red,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Black,

    CRGB::Red,
    CRGB::Red,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Black
};
void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 99;

    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
        if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
        if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
        if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
        if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
        if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
        if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
        if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
        if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
    }
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;

    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}


void loop()
{
    ChangePalettePeriodically();

    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */

    FillLEDsFromPaletteColors( startIndex);

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
