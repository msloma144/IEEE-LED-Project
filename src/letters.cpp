#include <string>
#include<vector>

std::vector<std::vector<bool>>  A1{
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1}
};

std::vector<std::vector<bool>>  B{
        {1, 1, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 0, 1},
        {1, 1, 0}
};

std::vector<std::vector<bool>>  C{
        {0, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
};

std::vector<std::vector<bool>>  D{
        {1, 1, 0},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 0}
};

std::vector<std::vector<bool>>  E{
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
};

std::vector<std::vector<bool>>  F{
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
};

std::vector<std::vector<bool>>  G{
       {0, 1, 1, 1, 0},
       {1, 1, 0, 0, 0},
       {1, 1, 0, 1, 1},
       {1, 1, 0, 0, 1},
       {0, 1, 1, 1, 0}
};

std::vector<std::vector<bool>>  H{
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1}
};


//protos
bool getLetterArray(char);
void returnFormmattedArr(std::string, int, int);


std::vector<std::vector<bool>> getLetterArray(char letter){
  switch (letter) {
  case 'A': return A;
  case 'B': return B;
  case 'C': return C;
  case 'D': return D;

  default : return false;
  }
}

void returnFormmattedArr(std::string input, int lineLength, int NUM_LEDS){
    //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
