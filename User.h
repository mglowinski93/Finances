#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class User
{
private:
    int id;
    string login;
    string haslo;

    public:
    User();
    int getId();
    string getLogin();
    string getPassword();
    void setId(int noweId);
    void setLogin(string nowyLogin);
    void setPassword(string newPassword);
};

#endif
