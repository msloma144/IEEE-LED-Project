#include <string>
#include <vector>
#include <FastLED.h>

std::vector<std::vector<bool>>  A{
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
        {1, 0, 0, 1}
};

std::vector<std::vector<bool>>  I{
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 0, 0}
};

std::vector<std::vector<bool>>  J{
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1}
};

std::vector<std::vector<bool>>  K{
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0}
};

std::vector<std::vector<bool>>  L{
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0}
};

std::vector<std::vector<bool>>  M{
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1}
};

std::vector<std::vector<bool>>  N{
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1}
};

std::vector<std::vector<bool>>  O{
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0}
};

std::vector<std::vector<bool>>  P{
        {1, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
};



std::vector<std::vector<bool>> getLetterArray(char letter){
  switch (letter) {
  case 'A': return A;
  case 'B': return B;
  case 'C': return C;
  case 'D': return D;
  case 'E': return E;
  case 'F': return F;
  case 'G': return G;
  case 'H': return H;
  case 'I': return I;
  case 'J': return J;
  case 'K': return K;
  case 'L': return L;
  case 'M': return M;
  case 'N': return N;
  case 'O': return O;
  case 'P': return P;

  default : return {{false}};
}
}

CRGB* processCharLine(std::vector<bool> line){
  CRGB ledPart[line.size()];

  for(i = 0; i < line.size(); i++){
    if(line[i]){
      ledPart.set(i, CRGB::Red);
    }
    else{
      ledPart[i] = CRGB::Black;
    }
  }

  return &ledPart;
}

CRGB* returnFormmattedArr(std::string input, int LINE_LENGTH, int NUM_LEDS){
    CRGB leds[NUM_LEDS];
    // string to char array
    int inputLength = input.length();
    char charInput[inputLength + 1];
    strcpy(charInput, input.c_str());

    int NUM_LINES = NUM_LEDS / LINE_LENGTH;

    for(i = 0; i < NUM_LINES; i++){
      for(int j = 0; j < inputLength; j++){
        std::vector<bool> lineTemp = getLetterArray(charInput[j])[i];

        for(int count = 0; count < LINE_LENGTH; i++){
          if(lineTemp[i])
        }
        //leds[i * LINE_LENGTH : i+1 * LINE_LENGTH] =
        //for()
      }
    }
    return null;
}
