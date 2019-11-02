#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class AdditionalFunctions
{
public:
    static string fromIntToString(int number);
    static int fromStringToInt(string number);
    static string charPosition(string text);
    static string getNumber(string text, int charPosition);
    static string getLine();
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static char getChar();
    static string makeFirstLetterBig(string text);
    static int getIntNumber();
    static void removeFile(string fileName);
    static void changeFileName(string oldFileName, string newFileName);
};


#endif
