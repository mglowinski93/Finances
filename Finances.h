#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>
#include "UsersManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class Finances
{
private:
    UsersManager usersManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    const string INCOMES_FILE_NAME, EXPENSES_FILE_NAME;

public:
    Finances(string userFileName, string incomeFileName, string expensesFileName):usersManager(userFileName), INCOMES_FILE_NAME(incomeFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        incomesManager = NULL;
        expensesManager = NULL;
    };
    ~Finances()
    {
        delete incomesManager;
        delete expensesManager;
        incomesManager = NULL;
        expensesManager = NULL;
    }
    void registerUser();
    User loginUser();
    User logoutUser();
    void changePasswordOfLoggedUser(User loggedUser);
    void addIncome(int loggedUserId);
    void addExpense(int loggedUserId);
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showBalanceFromSpecifiedPeriod();
};

#endif // User_H
