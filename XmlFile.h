#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

using namespace std;

class XmlFile
{
    private:
        const string FILE_NAME;
    public:
        XmlFile(string fileName) : FILE_NAME(fileName) {};
        string getFileName();
        bool checkIfFileEmpty();
};
#endif // XML_FILE_H
