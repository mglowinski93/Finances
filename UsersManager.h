#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UsersManager
{
    private:
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User addNewUser();
    int getIdOfNewUser();
    bool checkIfLoginExists(string login);
    void saveAllUsersToFile();

    public:
    UsersManager(string userFileName):fileWithUsers(userFileName)
    {
        users = fileWithUsers.loadUsersFromFile();
    };
    void registerUser();
    User loginUser();
    User logoutUser();
    void changePasswordOfLoggedUser(User userToPasswordChange);
    bool checkIfUserLoggedIn();
};

#endif
