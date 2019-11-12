//#include <iostream>
#include "letters.h"
#include <FastLED.h>

using namespace std;


int get_max_length(char word[], int line_width) {
    int max_line_length = 0;
    int content_length = 0;
    int line_pos;

    for (int index = 0; word[index] != '\0'; index++) {
        content_length += getLetterLength(word[index]);

        // account for small spaces
        if(&word[index] != "_" | &word[index] != "@" | &word[index] != "."){
          content_length += getLetterLength(*"");
        }
    }

    line_pos = 0;

    // iter through each letter in string
    for (int index = 0; word[index] != '\0'; index++) {
        int letter_len = getLetterLength(word[index]);

        // add letter length
        for (int j = 0; j < letter_len; j++) {
            line_pos++;
            max_line_length++;
        }
        // account for small spaces between letters
        if(&word[index] != "_" | &word[index] != "@" | &word[index] != "."){
          line_pos++;
          max_line_length++;
        }
    }

    // add length of sign at end for blank trailing string
    if (line_pos < (content_length + line_width)) {
        for (int j = line_pos; j < (content_length + line_width); j++) {
            max_line_length++;
        }
    }
    Serial.println(max_line_length);

    return max_line_length;
}


bool* form_matrix(char word[], int line_width, int num_lines) {
    int max_length = 0;
    int curr_length = 0;
    int content_length = 0;

    int line_pos;
    int max_positons;
    bool *output;
    int raw_letter_string_len;

    // get content width
    for (int index = 0; word[index] != '\0'; index++) {
        content_length += getLetterLength(word[index]);

        // account for small spaces
        if(&word[index] != "_" | &word[index] != "@" | &word[index] != "."){
          content_length += getLetterLength(*"");
        }
        raw_letter_string_len += 1;
    }

    max_positons = (content_length + line_width) * num_lines;
    output = new bool[max_positons];

    // build matrix
    for (int line_num = 0; line_num < num_lines; line_num++) {
        line_pos = 0;

        // fills line with letters
        for (int index = 0; index < raw_letter_string_len; index++) {
            bool *x = getLetterArray(word[index], line_num);
            int letter_len = getLetterLength(word[index]);

            // add letter for this line
            for (int j = 0; j < letter_len; j++) {
                output[curr_length] = x[j];
                curr_length++;
                line_pos++;

                if (line_num == 0) {
                    max_length++;
                }
            }

            // add small space between letters
            if(&word[index] != "_" | &word[index] != "@" | &word[index] != "."){
              bool *x = getLetterArray(*"", line_num);
              int letter_len = getLetterLength(*"");

              for (int j = 0; j < letter_len; j++) {
                  output[curr_length] = x[j];
                  curr_length++;
                  line_pos++;

                  if (line_num == 0) {
                      max_length++;
                  }
              }
            }
        }
        //Serial.println(line_pos);

        // if space still remains on line, fill with spaces
        if (line_pos < (content_length + line_width)) {
            for (int j = line_pos; j < (content_length + line_width); j++) {
                output[curr_length] = 0;
                curr_length++;
                line_pos++;

                if (line_num == 0) {
                    max_length++;
                }
            }
        }
        //Serial.println(line_pos);

        if(line_num == 0){
          for(int b = 0; b < content_length + line_width; b++){
            Serial.print(output[b]);
            Serial.print(" ");
          }
        }
        else{
          for(int b = (content_length + line_width) * line_num; b < (content_length + line_width) * (line_num + 1); b++){
            Serial.print(output[b]);
            Serial.print(" ");
          }
        }
        Serial.println();
    }
    //***************************
    //for (int i = 0; i < num_lines; i++){
    //  if(i == 0){
    //    for(int b = 0; b < content_length + line_width; b++){
    //      Serial.print(output[b]);
    //      Serial.print(" ");
    //    }
    //  }
    //  else{
    //    for(int b = (content_length + line_width) * i; b < (content_length + line_width) * (i + 1); b++){
    //      Serial.print(output[b]);
    //      Serial.print(" ");
    //    }
    //  }
    //  Serial.println();
    //}

    return output;
}


void scroll(bool* window, int line_width, int num_lines, int max_length, bool* output,
            int start, int end) {
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
}


#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define LED_PIN     5
#define BRIGHTNESS  128
#define UPDATES_PER_SECOND 100

#define num_lines 10
#define num_leds 28 * num_lines

int line_width = num_leds / num_lines;

CRGB leds[num_leds];

// start line two at an offset so it doesn't line up
// and look confusing
int start_one = 0;
int start_two = 5; // so the lines are offset

int end_one = line_width;
int end_two = line_width + 5; // so the lines are offset

bool *window_one;
bool *window_two;
bool *window;

bool *matrix_one;
bool *matrix_two;

int max_length_one;
int max_length_two;

int line_size;


void check_start_end(int max_length, int num){
  if (num == 1){
      if (start_one < max_length)
        start_one++;
      else
        start_one = 0;

      if (end_one < max_length)
        end_one++;
      else
        end_one = 0;
    }
    else if (num == 2){
        if (start_two < max_length)
          start_two++;
        else
          start_two = 0;

        if (end_two < max_length)
          end_two++;
        else
          end_two = 0;
      }
}


void setup() {
    delay( 3000 ); // power-up safety delay

    // lines need to be only capital letters
    char line_one[] = "WELCOME";
    char line_two[] = "STEM EVENT";
    Serial.begin(9600);

    matrix_one = form_matrix(line_one, line_width, num_lines / 2);
    max_length_one = get_max_length(line_one, line_width);

    matrix_two = form_matrix(line_two, line_width, num_lines / 2);
    max_length_two = get_max_length(line_two, line_width);

    line_size = line_width * (num_lines / 2);

    for( int i = 0; i < num_lines / 2; i++){
      for( int j = 0; j < max_length_one; j++){
        Serial.print(matrix_one[i * max_length_one + j]);
        Serial.print(" ");
      }
      Serial.print("\r\n");
    }
    Serial.print("\r\n");

    for( int i = 0; i < num_lines / 2; i++){
      for( int j = 0; j < max_length_two; j++){
        Serial.print(matrix_two[i * max_length_two + j]);
        Serial.print(" ");
      }
      Serial.print("\r\n");
    }
    Serial.print("\r\n");

    window_one = new bool[line_size];
    window_two = new bool[line_size];
    window = new bool[num_lines * line_width];

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, num_leds).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    clear_letters();
    Serial.print("Loaded");
}


void loop(){
    // updates window
    scroll(window_one, line_width, num_lines, max_length_one, matrix_one, start_one, end_one);
    scroll(window_two, line_width, num_lines, max_length_two, matrix_two, start_two, end_two);
    // add in line one
    for(int i = 0; i < line_size; i++){
        window[i] = window_one[i];
    }

    // add in line two
    for(int i = 0; i < line_size; i++){
        window[line_size + i] = window_two[i];
    }

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

    check_start_end(max_length_one, 1);
    check_start_end(max_length_two, 2);

    Serial.println();

    //delay(500);

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
