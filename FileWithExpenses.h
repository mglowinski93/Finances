#ifndef FILE_WITH_EXPENSES_H
#define FILE_WITH_EXPENSES_H

#include "Expense.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "AdditionalFunctions.h"
#include "XmlFile.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
private:
        string EXPENSES_STRING = "EXPENSES";
        string EXPENSE_STRING = "EXPENSE";
        string EXPENSE_ID_STRING = "EXPENSE_ID";
        string USER_ID_STRING = "USER_ID";
        string TITLE_STRING = "TITLE";
        string AMOUNT_STRING = "AMOUNT";
        string DATE_STRING = "DATE";
        int lastExpenseId;
        void saveExpensesToFile(const vector <Expense> &expenses);
        Expense enterDataForNewExpense(int);

public:
    FileWithExpenses(string fileName) : XmlFile(fileName), lastExpenseId(0){};
    vector <Expense> loadExpensesOfLoggedUser(int loggedUserId);
    void addExpense(int loggedUserId, vector <Expense> &expenses);
};

#endif
