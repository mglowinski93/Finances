#ifndef INCOME_MANAGER_H
#define INCOME_MANAGER_H

#include <vector>
#include "Income.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesManager
{

private:
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    void showIncome(const Income);

public:
    IncomesManager(string incomeFileName, int loggedUserId): fileWithIncomes(incomeFileName), LOGGED_USER_ID(loggedUserId)
    {
       incomes = fileWithIncomes.loadIncomesOfLoggedUser(LOGGED_USER_ID);
    };
    void showIncomes(const vector <Income> &incomesToShow);
    void addIncome();
    vector <Income> prepareIncomesBasedOnDate(int upperDate, int lowerDate);
    float calculateSumOfIncomes(const vector <Income> &incomesToSum);
};

#endif // INCOME_MANAGER
