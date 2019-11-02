#include "User.h"

User::User()
{
    id = -1;
    login = "";
    haslo = "";
}

int User::getId()
{
    return id;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return haslo;
}

void User::setId(int noweId)
{
    if(noweId > 0)
    {
        id = noweId;
    }
}

void User::setLogin(string nowyLogin)
{
    login = nowyLogin;
}

void User::setPassword(string newPassword)
{
    haslo = newPassword;
}
