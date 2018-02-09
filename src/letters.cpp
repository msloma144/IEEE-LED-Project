#include <string>
#include <vector>
#include "lettersLib.h"
#include <FastLED.h>
#include <ctype.h>


//protos
//std::vector<std::vector<bool>> getLetterArray(char);
//void returnFormmattedArr(std::string, int, int, CRGB); // returns led array
//void processCharLine(std::vector<bool>, CRGB); // returns led array (part)


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

  for(unsigned int i = 0; i < line.size(); i++){
    if(line[i]){
      ledPart[i] = CRGB::Red;
    }
    else{
      ledPart[i] = CRGB::Black;
    }
  }
}

char* inputToChar(std::string input, int inputLength){
  char *charInput;
  charInput = new char[inputLength + 1];
  return strcpy(charInput, input.c_str());
}

 std::vector<std::vector<bool>> charToMatrix(char inputArr[], int LINE_LENGTH){
  std::vector<std::vector<bool>> matrix;
  int inputLength = *(&inputArr + 1) - inputArr;

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < inputLength; j++){
      //add the letter matrix part for the current line
      //matrix.at(i).push_back(getLetterArray(inputArr[j]).at(i))
      std::vector<bool> temp = getLetterArray(inputArr[j]).at(i);
      std::vector<bool> line = matrix.at(i); //might work
      line.insert(line.end(), temp.begin(), temp.end());

      //add small space if current char AND next char are alpha
      if(isalpha(inputArr[j]) && isalpha(inputArr[j+1])){
        std::vector<bool> temp = getLetterArray('_').at(i);
        std::vector<bool> line = matrix.at(i); //might work
        line.insert(line.end(), temp.begin(), temp.end());
      }
    }
  }
  while((matrix.at(0).size() % LINE_LENGTH) != 0){
    for(unsigned int i = 0; i < matrix.size(); i++){
      for (size_t j = 0; j < matrix.at(0).size(); j++) {
        matrix.at(i).push_back(0);
      }
    }
  }

  return matrix;
}

std::vector<std::vector<CRGB>> setColors(std::vector<std::vector<bool>> matrix){
  std::vector<std::vector<CRGB>> colorMatrix(matrix.size());
  //initialize colorMatix to same size as martix
  for(unsigned int i = 0; i < matrix.size(); i++){
    colorMatrix.at(i) = std::vector<CRGB>(matrix.at(0).size());

    for(unsigned int j = 0; j < matrix.at(0).size(); j++){
      if(matrix.at(i).at(j)){
        colorMatrix.at(i).assign(j , CRGB::Red);
      }
      else{
        colorMatrix.at(i).assign(j , CRGB::Black);
      }
    }
  }
  return colorMatrix;
}

void matrixToArr(){
  //turns vector<vector<CRGB>> into CRGB 1d array

}

void slideView(std::vector<std::vector<CRGB>> colorMatrix, unsigned int LINE_LENGTH, unsigned int count){
  //takes in colorMatrix and returns CRGB 1d array
  std::vector<std::vector<CRGB>> outputMatrix(colorMatrix.size());

  for(unsigned int i = 0; i < colorMatrix.size(); i++){
    //outputMatrix.at(i) = std::vector<CRGB>(colorMatrix.at(i).begin() + count, colorMatrix.at(i).end() - LINE_LENGTH);

  }
}

void returnFormmattedArr(std::string input, int LINE_LENGTH, int NUM_LEDS){
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
