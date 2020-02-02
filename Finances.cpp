#include "Finances.h"

void Finances::registerUser()
{
    usersManager.registerUser();
}

User Finances::loginUser()
{
    User temp = usersManager.loginUser();
    if(usersManager.checkIfUserLoggedIn())
    {
        incomesManager = new IncomesManager(INCOMES_FILE_NAME, temp.getId());
        expensesManager = new ExpensesManager(EXPENSES_FILE_NAME, temp.getId());
    }
    return temp;
}

User Finances::logoutUser()
{
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
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
    incomesManager -> addIncome();
}

void Finances::showAllExpenses()
{
    expensesManager -> showAllExpenses();
}

void Finances::addExpense(int loggedUserId)
{
    expensesManager -> addExpense();
}

void Finances::showCurrentMonthBalance()
{

}

void Finances::showPreviousMonthBalance()
{
}
