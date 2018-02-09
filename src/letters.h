#include <vector>
#include <string>
#include <FastLED.h>

std::vector<std::vector<bool>> getLetterArray(char);
void processCharLine(std::vector<bool>);
char* inputToChar(std::string, int);
std::vector<std::vector<bool>> charToMatrix(char, int);
std::vector<std::vector<CRGB>> setColors(std::vector<std::vector<bool>>);
void slideView(std::vector<std::vector<CRGB>> colorMatrix, unsigned int, unsigned int);
void returnFormmattedArr(std::string, int, int);
