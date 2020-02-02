#include "AdditionalFunctions.h"

string AdditionalFunctions::fromIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AdditionalFunctions::fromStringToInt(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string AdditionalFunctions::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AdditionalFunctions::chooseOptionFromMainMenu()
{
    char choice;

    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "9. End Program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AdditionalFunctions::getChar();

    return choice;
}

char AdditionalFunctions::chooseOptionFromUserMenu()
{
    char choice;

    cout << " >>> User Menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from current month" << endl;
    cout << "4. Balance from previous month" << endl;
    cout << "5. Balance from particular period of time" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AdditionalFunctions::getChar();

    return choice;
}

char AdditionalFunctions::getChar()
{
    string input = "";
    char singleChar  = {0};
    cin.clear();
    fflush(stdin);

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            singleChar = input[0];
            break;
        }
        cout << "This is not single choice. Try one more time." << endl;
    }
    return singleChar;
}

string AdditionalFunctions::charPosition(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AdditionalFunctions::getIntNumber()
{
    string input = "";
    int number = 0;
    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not a number. Try one more time" << endl;
    }
    return number;
}

void AdditionalFunctions::removeFile(string fileName)
{
    if (remove(fileName.c_str()) == 0)
    {

    }
    else
    {
        cout << "Failed to remove file " << fileName << endl;
    }
}

void AdditionalFunctions::changeFileName(string oldFileName, string newFileName)
{
    if (rename(oldFileName.c_str(), newFileName.c_str()) == 0)
    {

    }
    else
    {
        cout << "Failed to change file name" << oldFileName << endl;
    }
}

string AdditionalFunctions::getCurrentDate()
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return buf;
}

bool AdditionalFunctions::isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool AdditionalFunctions::checkIfDateIsValid(string date)
{
    int y = fromStringToInt(date.substr(0,4));
    int m = fromStringToInt(date.substr(5,2));
    int d = fromStringToInt(date.substr(8,2));
    if (y > 9999 || y < 1800)
        return false;

    if (m < 1 || m > 12)
        return false;

    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        if(isLeap(y))
        {
            return (d <= 29);
        }else
        {
            return (d <= 28);
        }
    }

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

string AdditionalFunctions::getAmountString()
{
    string rawAmount = getLine();
    for(int i=0; i < rawAmount.size(); i++)
    {
        if(rawAmount[i] == ',')
            rawAmount[i] = '.';
    }
    return rawAmount;
}
