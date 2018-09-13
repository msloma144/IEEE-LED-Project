#include <iostream>
#include "letters.h"
#include <FastLED.h>

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


void scroll(bool* window, int line_width, int num_lines, int max_length, bool output[],
            int start, int end) {

    //bool *window = new bool[num_lines * line_width];

    int index = 0;
    for (int j = 0; j < num_lines; j++) {
        if (start < end) {
            for (int k = start; k < end; k++) {
                int get_index = k + (j * max_length);
                window[index] = output[get_index];
                index++;
            }
        }
        else {
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

    //return window;
}


#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define LED_PIN     5
#define BRIGHTNESS  64
#define UPDATES_PER_SECOND 100

#define num_leds 29 * 5
int num_lines = 5;
int line_width = num_leds / num_lines;

CRGB leds[num_leds];

int max_iter = 10000;
int i = 0;
int start = 0;
int end = line_width;

bool *matrix;
int max_length;
bool *window;


void check_start_end(int max_length){
  if (start < max_length)
      start++;
  else
      start = 0;

  if (end < max_length)
      end++;
  else
      end = 0;
}


void setup() {
    delay( 5000 ); // power-up safety delay

    char word[] = "A B A A C";
    Serial.begin(9600);

    matrix = form_matrix(word, line_width, num_lines);
    max_length = get_max_length(word, line_width);
    window = new bool[num_lines * line_width];

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, num_leds).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}


void loop(){
    // updates window
    scroll(window, line_width, num_lines, max_length, matrix, start, end);

    Serial.println("");

    for(int i = 0; i < num_leds; i++){
      if( i % (line_width) == 0 && i != 0){
        Serial.print("\r\n");
      }

      // for matrix
      Serial.print(window[i]);
      Serial.print(" ");

      if (window[i]){
        leds[i] = CRGB::Red;
      }
      else{
        leds[i] = CRGB::Black;
      }
    }

    check_start_end(max_length);

    Serial.println();

    delay(500);

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
