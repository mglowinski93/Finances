#include "User.h"

User::User()
{
    id = -1;
    login = "";
    password = "";
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
    return password;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

void User::setId(int id)
{
    if(id > 0)
    {
        this -> id = id;
    }
}

void User::setLogin(string login)
{
    this -> login = login;
}

void User::setPassword(string password)
{
    this -> password = password;
}

void User::setName(string name)
{
    this -> name = name;
}

void User::setSurname(string surname)
{
    this -> surname = surname;
}
