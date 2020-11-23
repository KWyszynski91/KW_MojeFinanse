#include "AuxiliaryMethods.h"

string AuxiliaryMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::floatToStringConversion(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine()
{
    string enterStream = "";
    cin.clear();
    cin.sync();
    getline(cin, enterStream);
    return enterStream;
}

string AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::stringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

float AuxiliaryMethods::stringToFloatConversion(string number)
{
    float numberFlo;
    istringstream iss(number);
    iss >> numberFlo;
    return numberFlo;
}

char AuxiliaryMethods::loadSign()
{
    string enterStream = "";
    char sign  = {0};
    while (true)
    {
        cin.clear();
        cin.sync();
        getline(cin, enterStream);

        if (enterStream.length() == 1)
        {
            sign = enterStream[0];
            break;
        }
        cout << "This is not a single sign. Please retype." << endl;
    }
    return sign;
}

double AuxiliaryMethods::loadFloat()
{
    string enterStream = "";
    double number = 0;
    while (true)
    {
        cin.ignore();
        getline(cin, enterStream);
        stringstream myStream(enterStream);
        if (myStream >> number)
            break;
        cout << "This is not a number. Please retype. " << endl;
    }
    return number;
}

string AuxiliaryMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

float AuxiliaryMethods::changeCommaToDot(string strAmount)
{
    float amount=0;
    string searchComma=",";
    size_t position=strAmount.find(searchComma);
    if (position != string::npos)
    {
        strAmount.replace(position,1,".");
    }
    amount=stringToFloatConversion(strAmount);
    return amount;
}
