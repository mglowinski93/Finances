#include "TextFile.h"

string TextFile::getFileName()
{
    return FILE_NAME;
}

bool TextFile::checkIfFileEmpty()
{
    bool empty = true;
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            empty = false;
    }

    textFile.close();
    return empty;
}
