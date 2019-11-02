#include "UsersManager.h"

bool UsersManager::checkIfUserLoggedIn()
{
    if(loggedUserId > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

void UsersManager::registerUser()
{
    User user = addNewUser();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Account was successfully created" << endl << endl;
}

User UsersManager::addNewUser()
{
    User user;
    user.setId(getIdOfNewUser());
    string login;
    while(true)
    {
        cout << "Type login: ";
        cin >> login;
        user.setLogin(login);
        if(checkIfLoginExists(user.getLogin()) == true)
        {
            cout << "Login already taken. Try with another one."<<endl;
        }else
        {
            break;
        }
    }

    cout << "Type password: ";
    string password;
    cin >> password;
    user.setPassword(password);

    return user;
}

int UsersManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UsersManager::checkIfLoginExists(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
            return true;
        return false;
    }
}

User UsersManager::logoutUser()
{
    User emptyUser;
    loggedUserId = emptyUser.getId();
    return emptyUser;
}

User UsersManager::loginUser()
{
    User emptyUser;
    string login = "", password = "";
    cout << endl << "Type login: ";
    login = AdditionalFunctions::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int triesCounter = 3; triesCounter > 0; triesCounter--)
            {
                cout << "Type password. Tries left: " << triesCounter << ": ";
                password = AdditionalFunctions::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Logged in" << endl << endl;
                    loggedUserId = itr->getId();
                    return *itr;
                }
            }
            cout << "Wrong password was typed 3 times" << endl;
            return emptyUser;
        }
        itr++;
    }
    cout << "There is no user with such a login" << endl << endl;
    return emptyUser;
}

void UsersManager::saveAllUsersToFile()
{
    fileWithUsers.saveAllUsersToFile(users);
}

void UsersManager::changePasswordOfLoggedUser(User userToPasswordChange)
{
    string newPassword = "";
    cout << "Type new password: ";
    newPassword = AdditionalFunctions::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == userToPasswordChange.getId())
        {
            itr -> setPassword(newPassword);
            cout << "Password was reseted" << endl << endl;
        }
    }
    saveAllUsersToFile();
}
