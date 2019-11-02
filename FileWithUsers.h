#ifndef PLIK_Z_UZYTKOWNIKAMI
#define PLIK_Z_UZYTKOWNIKAMI

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "User.h"
#include "AdditionalFunctions.h"
#include "vector"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile
{
private:
    string zamienDaneUseraNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
    User pobierzDaneUsera(string daneJednegoUseraOddzielonePionowymiKreskami);

public:
    FileWithUsers(string userFileName): TextFile(userFileName){};
    void addUserToFile(User user);
    vector <User> wczytajUserowZPliku();
    void saveAllUsersToFile(vector <User
                                       > users);
};

#endif // PLIK_Z_UZYTKOWNIKAMI
