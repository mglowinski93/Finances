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
    static string getLine();
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static char getChar();
    static void removeFile(string fileName);
    static void changeFileName(string oldFileName, string newFileName);
    static string getCurrentDate();
    static string getCurrentYear();
    static string getCurrentMonth();
    static string getPreviousMonth();
    static string getYearFromLastYearMonth();
    static bool checkIfDateIsValid(string);
    static string getAmountString();
    static string convertDateFromIntToString(int);
    static int convertDateFromStringToInt(string);

};


#endif
