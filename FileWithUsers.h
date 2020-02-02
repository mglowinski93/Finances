#ifndef PLIK_Z_UZYTKOWNIKAMI
#define PLIK_Z_UZYTKOWNIKAMI

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "User.h"
#include "AdditionalFunctions.h"
#include "vector"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{
private:
    string USER_ID_STRING = "USER_ID";
    string USERS_STRING = "USERS";
    string USER_STRING = "USER";
    string NAME_STRING = "NAME";
    string SURNAME_STRING = "SURNAME";
    string LOGIN_STRING = "LOGIN";
    string PASSWORD_STRING = "PASSWORD";

public:
    FileWithUsers(string userFileName): XmlFile(userFileName){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif // PLIK_Z_UZYTKOWNIKAMI
