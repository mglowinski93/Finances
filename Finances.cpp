#include "Finances.h"

void Finances::registerUser()
{
    usersManager.registerUser();
}

User Finances::loginUser()
{
    User temp = usersManager.loginUser();
    if(usersManager.checkIfUserLoggedIn())
        incomesManager = new IncomesManager(INCOMES_FILE_NAME, temp.getId());
    return temp;
}

User Finances::logoutUser()
{
    delete incomesManager;
    incomesManager = NULL;
    return usersManager.logoutUser();
}

void Finances::changePasswordOfLoggedUser(User loggedUser)
{
    usersManager.changePasswordOfLoggedUser(loggedUser);
}

void Finances::showAllIncomes()
{
    incomesManager ->showAllIncomes();
}

void Finances::addIncome(int loggedUserId)
{
    if(usersManager.checkIfUserLoggedIn())
    {
        incomesManager -> addIncome();
    }else
    {
        cout << "First you need to be logged in. "<<endl;
    }
}

void Finances::removeIncome()
{
    incomesManager -> removeIncome();
}

void Finances::editIncome()
{
    incomesManager -> editIncome();
}
