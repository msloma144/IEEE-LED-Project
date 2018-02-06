#include <string>
#include <vector>
#include "lettersLib.cpp"
#include <FastLED.h>


//protos
std::vector<std::vector<bool>> getLetterArray(char);
CRGB* returnFormmattedArr(std::string, int, int); // returns led array
CRGB* processCharLine(std::vector<bool>); // returns led array (part)


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
  case 'Q': return Q;
  case 'R': return R;
  case 'S': return S;
  case 'T': return T;
  case 'U': return U;
  case 'V': return V;
  case 'W': return W;
  case 'X': return X;
  case 'Y': return Y;
  case 'Z': return Z;
  case ' ': return space_large;
  case '_': return space_small; //figure out letter space
  //potato

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
