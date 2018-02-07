#include <string>
#include <vector>
#include "lettersLib.cpp"
#include <FastLED.h>
#include <ctype.h>


//protos
std::vector<std::vector<bool>> getLetterArray(char);
void returnFormmattedArr(std::string, int, int, CRGB); // returns led array
void processCharLine(std::vector<bool>, CRGB); // returns led array (part)


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

  default : return {{false}};
}
}

void processCharLine(std::vector<bool> line){
  CRGB ledPart[line.size()];

  for(int i = 0; i < line.size(); i++){
    if(line[i]){
      ledPart[i] = CRGB::Red;
    }
    else{
      ledPart[i] = CRGB::Black;
    }
  }
}

char* inputToChar(std::string input, int inputLength){
  char charInput[inputLength + 1];
  return strcpy(charInput, input.c_str());
}

void charToMatrix(char inputArr[]){
  std::vector<std::vector<bool>> matrix;
  int inputLength = *(&inputArr + 1) - inputArr;

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < inputLength; j++){
      //add the letter matrix part for the current line
      matrix.at(i).push_back(getLetterArray(inputArr[j]).at(i))

      //add small space if current char AND next char are alpha
      if(isalpha(inputArr[j]) && isalpha(inputArr[j+1])){
        matrix.at(i).push_back(getLetterArray('_').at(i))
      }
    }
  }
  //return matrix;
}

void setColors(std::vector<std::vector<bool>> matrix){
  std::vector<std::vector<CRGB>> colorMatrix;
  //initialize colorMatix to same size as martix
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix.at(0).size(); j++){
      if(matrix.at(i).at(j)){
        colorMatrix.at(i).assign(j , CRGB::Black);
      }
      else{
        colorMatrix.at(i).assign(j , CRGB::Black);
      }
    }
  }
}
void matrixToArr(){
  //turns vector<vector<CRGB>> into CRGB 1d array
}
void slideView(){
  //returns CRGB 1d array
}

void returnFormmattedArr(std::string input, int LINE_LENGTH, int NUM_LEDS, CRGB &leds){
    // string to char array
    int inputLength = input.length();
    char *charInput = inputToChar(input, input.length());

    int NUM_LINES = NUM_LEDS / LINE_LENGTH;

    for(int i = 0; i < NUM_LINES; i++){
      for(int j = 0; j < inputLength; j++){
        std::vector<bool> lineTemp = getLetterArray(charInput[j])[i];

        for(int count = 0; count < LINE_LENGTH; i++){
          //if(lineTemp[i])
        }
        //leds[i * LINE_LENGTH : i+1 * LINE_LENGTH] =
        //for()
      }
    }
    //return null;
}
