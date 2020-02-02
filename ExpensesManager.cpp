#include "ExpensesManager.h"

void ExpensesManager::showExpense(Expense expense)
{
    cout << expense.getTitle() << " at " << expense.getDate() << " for " << expense.getAmount() << " amount" << endl;
}

void ExpensesManager::showAllExpenses()
{
    for(vector<Expense>::iterator it = expenses.begin(); it != expenses.end(); ++it)
    {
        showExpense(*it);
    }
}

void ExpensesManager::addExpense()
{
    fileWithExpenses.addExpense(LOGGED_USER_ID, expenses);
}
