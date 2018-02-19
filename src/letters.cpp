#include <string>
#include <vector>
#include "lettersLib.h"
#include <FastLED.h>
#include <ctype.h>
#include <cstring>


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

//DEPRECIATED
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

char* inputToChar(std::string input){
  int inputLength = input.length();
  char *charInput;

  charInput = new char[inputLength + 1];
  return strcpy(charInput, input.c_str());
}

std::vector<std::vector<bool>> charToMatrix(char inputArr[], unsigned int inputLength, unsigned int LINE_LENGTH){
  //takes in the array of chars (input) and converts them into
  //a boolean matrix as prescribed by their corresponding letter matrix
  //in lettersLib

  std::vector<std::vector<bool>> matrix(5);

  for(unsigned int i = 0; i < 5; i++){


    for(unsigned int j = 0; j < inputLength; j++){
      //add the letter matrix part for the current line
      std::vector<bool> temp = getLetterArray(inputArr[j]).at(i);
      matrix.at(i).insert(matrix.at(i).end(), temp.begin(), temp.end());

      //add small space if current char AND next char are alpha
      if(isalpha(inputArr[j]) && isalpha(inputArr[j+1])){
        temp = getLetterArray('_').at(i);
          matrix.at(i).insert(matrix.at(i).end(), temp.begin(), temp.end());
      }
    }
  }

  while((matrix.at(0).size() % LINE_LENGTH) != 0){
    //add spaces to the end of the line till the matrix has a moduluo many columns as
    //there are pixels
    for(unsigned int i = 0; i < matrix.size(); i++){
      matrix.at(i).push_back(0);
    }
  }
  return matrix;
}

std::vector<std::vector<CRGB>> setColors(std::vector<std::vector<bool>> matrix){
  std::vector<std::vector<CRGB>> colorMatrix(matrix.size());
  //initialize colorMatix to same size as martix
  for(unsigned int i = 0; i < matrix.size(); i++){
    colorMatrix.at(i) = std::vector<CRGB>();

    for(unsigned int j = 0; j < matrix.at(0).size(); j++){
      if(matrix.at(i).at(j)){
        colorMatrix.at(i).push_back(CRGB::Red);
      }
      else{
        colorMatrix.at(i).push_back(CRGB::Black);
      }
    }
  }
  return colorMatrix;
}

CRGB* matrixToArr(std::vector<std::vector<CRGB>> colorMatrix){
  //turns vector<vector<CRGB>> into CRGB 1d array
  unsigned int height = colorMatrix.size();
  unsigned int width = colorMatrix.at(0).size();
  unsigned int arrayLength = height * width;
  CRGB *array;
  array = new CRGB[arrayLength];

  unsigned int counter = 0;

  for(unsigned int i = 0; i < height; i++){
    for(unsigned int j = 0; i < width; j++)
    array[counter] = colorMatrix.at(i).at(j);
    counter++;
  }
  return array;
}

std::vector<std::vector<CRGB>> stringtoColor(std::string input, int LINE_LENGTH, int NUM_LEDS){
    //int NUM_LINES = NUM_LEDS / LINE_LENGTH;
    char* charInput;
    charInput = inputToChar(input);
    unsigned int inputLength = input.length();

    std::vector<std::vector<bool>> boolMatrix = charToMatrix(charInput, inputLength, LINE_LENGTH);
    std::vector<std::vector<CRGB>> colorMatrix = setColors(boolMatrix);

    return colorMatrix;
}

CRGB* slideView(std::vector<std::vector<CRGB>> colorMatrix, unsigned int LINE_LENGTH, unsigned int count){
  Serial.println("Entered...");
  //takes in colorMatrix and returns CRGB 1d array
  std::vector<std::vector<CRGB>> outputMatrix(colorMatrix.size());

  for(unsigned int i = 0; i < colorMatrix.size(); i++){
    //get subsection of vector for output
    outputMatrix.at(i) = std::vector<CRGB>();

    for(unsigned int j = count; j < LINE_LENGTH + count; j++){
      outputMatrix.at(i).push_back(colorMatrix.at(i).at(j));

    }
    Serial.println(i);
  }

  Serial.println("Shifted...");
  CRGB *output;
  output = matrixToArr(outputMatrix);
  Serial.println("PREP...");
  return output;
}
