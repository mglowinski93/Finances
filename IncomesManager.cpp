#include "IncomesManager.h"

void IncomesManager::showIncome(Income income)
{
    cout << income.getTitle() << " at " << income.getDate() << " for " << income.getAmount() << " amount" << endl;
}

void IncomesManager::showAllIncomes()
{
    for(vector<Income>::iterator it = incomes.begin(); it != incomes.end(); ++it)
    {
        showIncome(*it);
    }
}

void IncomesManager::addIncome()
{
    fileWithIncomes.addIncome(LOGGED_USER_ID, incomes);
}
