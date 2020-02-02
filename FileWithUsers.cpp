#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    if (!xml.Load(getFileName().c_str()))
    {
       xml.AddElem(USERS_STRING);
    }else
    {
       xml.FindElem();
    }
    xml.IntoElem();
    xml.AddElem(USER_STRING);
    xml.IntoElem();
    xml.AddElem(USER_ID_STRING, user.getId());
    xml.AddElem(LOGIN_STRING, user.getLogin());
    xml.AddElem(PASSWORD_STRING, user.getPassword());
    xml.AddElem(NAME_STRING, user.getName());
    xml.AddElem(SURNAME_STRING, user.getSurname());
    xml.OutOfElem();
    xml.Save(getFileName().c_str());
}


vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    if (xml.Load( MCD_T(getFileName().c_str())))
    {
        xml.FindElem(); // ORDER element is root
        xml.IntoElem(); // inside ORDER
        while( xml.FindElem(USER_STRING) )
        {
            xml.FindChildElem(USER_ID_STRING);
            user.setId(AdditionalFunctions::fromStringToInt(xml.GetChildData()));
            xml.FindChildElem(LOGIN_STRING);
            user.setLogin(xml.GetChildData());
            xml.FindChildElem(PASSWORD_STRING);
            user.setPassword(xml.GetChildData());
            xml.FindChildElem(NAME_STRING);
            user.setName(xml.GetChildData());
            xml.FindChildElem(SURNAME_STRING);
            user.setSurname(xml.GetChildData());
            users.push_back(user);
        }
    }
    return users;
}


void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;
    xml.AddElem(USERS_STRING);
    xml.IntoElem();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        xml.AddElem(USER_STRING);
        xml.IntoElem();
        xml.AddElem(USER_ID_STRING, itr -> getId());
        xml.AddElem(LOGIN_STRING, itr -> getLogin());
        xml.AddElem(PASSWORD_STRING, itr -> getPassword());
        xml.AddElem(NAME_STRING, itr -> getName());
        xml.AddElem(SURNAME_STRING, itr -> getSurname());
        xml.OutOfElem();
    }
    xml.Save(getFileName().c_str());
}
