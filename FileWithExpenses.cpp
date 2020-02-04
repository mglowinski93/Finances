#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesOfLoggedUser(int loggedUserId)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    if(xml.Load( MCD_T(getFileName().c_str())))
    {
        xml.FindElem(); // EXPENSE element is root
        xml.IntoElem(); // inside ORDER
        while(xml.FindElem(EXPENSE_STRING))
        {
            xml.FindChildElem(EXPENSE_ID_STRING);
            int readedExpenseId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            if(readedExpenseId > lastExpenseId)
                lastExpenseId = readedExpenseId;
            expense.setId(readedExpenseId);
            xml.FindChildElem(USER_ID_STRING);
            expense.setUserId(AdditionalFunctions::fromStringToInt(xml.GetChildData()));
            xml.FindChildElem(TITLE_STRING);
            expense.setTitle(xml.GetChildData());
            xml.FindChildElem(AMOUNT_STRING);
            expense.setAmount(xml.GetChildData());
            xml.FindChildElem(DATE_STRING);
            expense.setDate(AdditionalFunctions::convertDateFromStringToInt(xml.GetChildData()));
            expenses.push_back(expense);
        }
    }

    return expenses;
}

void FileWithExpenses::saveExpensesToFile(const vector <Expense> &expenses)
{
    CMarkup xml;
    xml.AddElem(EXPENSES_STRING);
    xml.IntoElem();
    for(vector<Expense>::const_iterator it = expenses.begin(); it != expenses.end(); ++it)
    {
        xml.AddElem(EXPENSE_STRING);
        xml.IntoElem();
        xml.AddElem(EXPENSE_ID_STRING, it -> getId());
        xml.AddElem(USER_ID_STRING, it -> getUserId());
        xml.AddElem(TITLE_STRING, it -> getTitle());
        xml.AddElem(AMOUNT_STRING, it -> getAmount());
        xml.AddElem(DATE_STRING, AdditionalFunctions::convertDateFromIntToString(it -> getDate()));
        xml.OutOfElem();
    }
    xml.Save(getFileName().c_str());
}


Expense FileWithExpenses::enterDataForNewExpense(int loggedUserId)
{
    Expense expense;

    expense.setId(++lastExpenseId);
    expense.setUserId(loggedUserId);

    cout << "Type title: ";
    expense.setTitle(AdditionalFunctions::getLine());

    cout << "Type amount: ";
    expense.setAmount(AdditionalFunctions::getAmountString());

    cout << "Is it expense from today? [y/n]: ";
    string userInput;
    string expenseDate;
    cin >> userInput;
    if(userInput == "y" || userInput == "yes")
    {
        expenseDate = AdditionalFunctions::getCurrentDate();
    }else
    {
        cout << "Type date: ";
        cin >> expenseDate;
        while(!AdditionalFunctions::checkIfDateIsValid(expenseDate))
        {
            cout << "Date invalid. Type one more time: "<< endl;
            cin >> expenseDate;
        }
    }
    expense.setDate(AdditionalFunctions::convertDateFromStringToInt(expenseDate));

    return expense;
}


void FileWithExpenses::addExpense(int loggedUserId, vector <Expense> &expenses)
{
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    Expense newExpense = enterDataForNewExpense(loggedUserId);
    expenses.push_back(newExpense);
    sort(expenses.begin(), expenses.end());
    saveExpensesToFile(expenses);
    cout << "Expense added";
}
