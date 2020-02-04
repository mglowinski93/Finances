#include "ExpensesManager.h"

void ExpensesManager::showExpense(const Expense expense)
{
    cout << expense.getTitle() << " at " <<  AdditionalFunctions::convertDateFromIntToString(expense.getDate()) << " for " << expense.getAmount() << " amount" << endl;
}

void ExpensesManager::showExpenses(const vector <Expense> &expensesToShow)
{
    for(vector<Expense>::const_iterator it = expensesToShow.begin(); it != expensesToShow.end(); ++it)
    {
        showExpense(*it);
    }
}

void ExpensesManager::addExpense()
{
    fileWithExpenses.addExpense(LOGGED_USER_ID, expenses);
}

vector <Expense> ExpensesManager::prepareExpensesBasedOnDate(int lowerDate, int upperDate)
{
     vector <Expense> expensesWithinDate;

    for(vector<Expense>::iterator it = expenses.begin(); it != expenses.end(); ++it)
    {
        if(LOGGED_USER_ID == it-> getUserId() && it -> getDate() <= upperDate && it -> getDate() >= lowerDate)
            expensesWithinDate.push_back(*it);
    }
    return expensesWithinDate;
}
