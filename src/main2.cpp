#include <iostream>
#include "letters.h"
#include <FastLED.h>

#include "letters.h"

using namespace std;

int get_max_length(char word[], int line_width) {
    int max_length = 0;
    int content_length = 0;
    int line_pos;

    for (int index = 0; word[index] != '\0'; index++) {
        content_length += getLetterLength(word[index]);
    }

    line_pos = 0;

    for (int index = 0; word[index] != '\0'; index++) {
        int letter_len = getLetterLength(word[index]);

        for (int j = 0; j < letter_len; j++) {
            line_pos++;
            max_length++;
        }
    }

    if (line_pos < (content_length + line_width)) {
        for (int j = line_pos; j < (content_length + line_width); j++) {
            max_length++;
        }
    }

    return max_length;
}

bool* scroll(int line_width, int num_lines, int max_length, bool output[],
            int start, int end) {

    bool *window = new bool[num_lines * line_width];

    int index = 0;
    for (int j = 0; j < num_lines; j++) {
        if (start < end) {
            for (int k = start; k < end; k++) {
                int get_index = k + (j * max_length);
                window[index] = output[get_index];
                index++;
            }
        } else {
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

    return window;
}

bool* form_matrix(char word[], int line_width, int num_lines) {
    int max_length = 0;
    int curr_length = 0;
    int content_length = 0;

    int line_pos;
    int max_positons;
    bool *output;

    // get content width
    for (int index = 0; word[index] != '\0'; index++) {
        content_length += getLetterLength(word[index]);
    }

    max_positons = (content_length + line_width) * num_lines;
    output = new bool[max_positons];

    // build matrix
    for (int i = 0; i < num_lines; i++) {
        line_pos = 0;

        // fills line with letters
        for (int index = 0; word[index] != '\0'; index++) {
            bool *x = getLetterArray(word[index], i);
            int letter_len = getLetterLength(word[index]);

            for (int j = 0; j < letter_len; j++) {
                output[curr_length] = x[j];
                curr_length++;
                line_pos++;

                if (i == 0) {
                    max_length++;
                }
            }
        }

        // if space still remains on line, fill with spaces
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

    return output;
}




#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

int num_leds = 100;
int num_lines = 5;
int line_width = num_leds / num_lines;

int max_iter = 10000;
int i = 0;
int start = 0;
int end = line_width;

bool *matrix;
int max_length;

void setup() {
    delay( 3000 ); // power-up safety delay

    char word[] = "A B A A C";

    matrix = form_matrix(word, line_width, num_lines);
    max_length = get_max_length(word, line_width);

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}


void loop()
{
    bool* window = scroll(line_width, num_lines, max_length, matrix, start, end);

    for(int i = 0; i < num_leds; i++){
      if (window[i])
        leds[i] = CRGB::Red;
      else
        leds[i] = CRGB::Black;
    }

      if (start < max_length)
          start++;
      else
          start = 0;

      if (end < max_length)
          end++;
      else
          end = 0;

      delay(1000);

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
