#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
  public:
    static string intToStringConversion(int number);
    static string floatToStringConversion(float number);
    static string loadLine();
    static string changeFirstLetterToLargeAndRestToSmall(string text);
    static int stringToIntConversion(string number);
    static float stringToFloatConversion(string number);
    static char loadSign();
    static double loadFloat();
    static string getNumber(string text, int signPosition);
    static float changeCommaToDot(string strAmount);
    //static float conversMyStringToFloat(string strNumber);
};

#endif;
