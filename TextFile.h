#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{

    const string FILE_NAME;

public:

    TextFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    bool checkIfFileEmpty();
};
#endif // TEXT_FILE_H
