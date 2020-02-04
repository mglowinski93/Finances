#ifndef EXPENSES_MANAGER_H
#define EXPENSES_MANAGER_H

#include <vector>
#include "Expense.h"
#include "FileWithExpenses.h"

using namespace std;

class ExpensesManager
{
private:
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    void showExpense(const Expense);

public:
   ExpensesManager(string expenseFileName, int loggedUserId): fileWithExpenses(expenseFileName), LOGGED_USER_ID(loggedUserId)
   {
    expenses = fileWithExpenses.loadExpensesOfLoggedUser(LOGGED_USER_ID);
   };
   void showExpenses(const vector <Expense> &expensesToShow);
   void addExpense();
   vector <Expense> prepareExpensesBasedOnDate(int upperDate, int lowerDate);
   float calculateSumOfExpenses(const vector <Expense> &expensesToSum);
};

#endif //EXPENSES_MANAGER
