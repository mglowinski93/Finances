#ifndef USER_FILE_H
#define USER_FILE_H

#include <iostream>

using namespace std;

class User
{
private:
    int id;
    string login;
    string password;
    string name;
    string surname;

    public:
    User();
    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
};

#endif
