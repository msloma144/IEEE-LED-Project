#include <string>
#include <vector>
#include "lettersLib.cpp"
#include <FastLED.h>


//protos
std::vector<std::vector<bool>> getLetterArray(char);
void returnFormmattedArr(std::string, int, int);


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
  case 'L': return space_small; //figure out letter space

  default : return {{false}};
}
}

void returnFormmattedArr(std::string input, int lineLength, int NUM_LEDS){
    //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
