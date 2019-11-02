#include "Income.h"

int Income::getId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
}

string Income::getName()
{
    return name;
}

string Income::getSurname()
{
    return surname;
}

string Income::getPhoneNumber()
{
    return phoneNumber;
}

string Income::getEmail()
{
    return email;
}

string Income::getAddress()
{
    return adres;
}

void Income::setId(int id)
{
  this->id = id;
}

void Income::setUserId(int userId)
{
    this->userId = userId;
}

void Income::setName(string name)
{
    this-> name = name;
}

void Income::setSurname(string surname)
{
    this->surname = surname;
}

void Income::setPhoneNumber(string phoneNumber)
{
 this->phoneNumber = phoneNumber;
}

void Income::setEmail(string email)
{
    this->email = email;
}

void Income::setAddress(string adres)
{
    this->adres = adres;
}
