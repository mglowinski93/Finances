#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;

class AdditionalFunctions
{
private:
    static bool isLeap(int);
public:
    static string fromIntToString(int number);
    static int fromStringToInt(string number);
    static string charPosition(string text);
    static string getLine();
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static char getChar();
    static int getIntNumber();
    static void removeFile(string fileName);
    static void changeFileName(string oldFileName, string newFileName);
    static string getCurrentDate();
    static bool checkIfDateIsValid(string);
    static string getAmountString();
};


#endif
