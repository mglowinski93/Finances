#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    string liniaZDanymiUsera = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        liniaZDanymiUsera = zamienDaneUseraNaLinieZDanymiOddzielonaPionowymiKreskami(user);

        if (checkIfFileEmpty() == true)
        {
            textFile << liniaZDanymiUsera;
        }
        else
        {
            textFile << endl << liniaZDanymiUsera ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    textFile.close();
}

string FileWithUsers::zamienDaneUseraNaLinieZDanymiOddzielonaPionowymiKreskami(User user)
{
    string liniaZDanymiUsera = "";
    liniaZDanymiUsera += AdditionalFunctions::fromIntToString(user.getId())+ '|';
    liniaZDanymiUsera += user.getLogin() + '|';
    liniaZDanymiUsera += user.getPassword() + '|';

    return liniaZDanymiUsera;
}

vector <User> FileWithUsers::wczytajUserowZPliku()
{
    User user;
    vector <User> users;
    string daneJednegoUseraOddzielonePionowymiKreskami = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, daneJednegoUseraOddzielonePionowymiKreskami))
        {
            user = pobierzDaneUsera(daneJednegoUseraOddzielonePionowymiKreskami);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}


User FileWithUsers::pobierzDaneUsera(string daneJednegoUseraOddzielonePionowymiKreskami)
{
    User user;
    string pojedynczaDanaUsera = "";
    int numerPojedynczejDanejUsera = 1;

    for (int charPosition = 0; charPosition < daneJednegoUseraOddzielonePionowymiKreskami.length(); charPosition++)
    {
        if (daneJednegoUseraOddzielonePionowymiKreskami[charPosition] != '|')
        {
            pojedynczaDanaUsera += daneJednegoUseraOddzielonePionowymiKreskami[charPosition];
        }
        else
        {
            switch(numerPojedynczejDanejUsera)
            {
            case 1:
                user.setId(atoi(pojedynczaDanaUsera.c_str()));
                break;
            case 2:
                user.setLogin(pojedynczaDanaUsera);
                break;
            case 3:
                user.setPassword(pojedynczaDanaUsera);
                break;
            }
            pojedynczaDanaUsera = "";
            numerPojedynczejDanejUsera++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    fstream textFile;
    string liniaZDanymiUsera = "";
    vector <User>::iterator itrKoniec = --users.end();

    textFile.open(getFileName().c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            liniaZDanymiUsera = zamienDaneUseraNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               textFile << liniaZDanymiUsera;
            }
            else
            {
                textFile << liniaZDanymiUsera << endl;
            }
            liniaZDanymiUsera = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }
    textFile.close();
}
