#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesOfLoggedUser(int loggedUserId)
{
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;
    if(xml.Load( MCD_T(getFileName().c_str())))
    {
        int expenseId = -1;
        xml.FindElem(); // EXPENSE element is root
        xml.IntoElem(); // inside ORDER
        while(xml.FindElem(EXPENSE_STRING))
        {
            xml.FindChildElem(EXPENSE_ID_STRING);
            expenseId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            xml.FindChildElem(USER_ID_STRING);
            int assignedUserId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            if(loggedUserId == assignedUserId)
            {
                expense.setId(expenseId);
                expense.setUserId(assignedUserId);
                xml.FindChildElem(TITLE_STRING);
                expense.setTitle(xml.GetChildData());
                xml.FindChildElem(AMOUNT_STRING);
                expense.setAmount(xml.GetChildData());
                xml.FindChildElem(DATE_STRING);
                expense.setDate(xml.GetChildData());
                expenses.push_back(expense);
            }
        }
        lastExpenseId = expenseId;
    }

    return expenses;
}

void FileWithExpenses::saveExpenseToFile(const Expense expense)
{
    CMarkup xml;
    if (!xml.Load(getFileName().c_str()))
    {
       xml.AddElem(EXPENSES_STRING);
    }else
    {
       xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem(EXPENSE_STRING);
    xml.IntoElem();
    xml.AddElem(EXPENSE_ID_STRING, expense.getId());
    xml.AddElem(USER_ID_STRING, expense.getUserId());
    xml.AddElem(TITLE_STRING, expense.getTitle());
    xml.AddElem(AMOUNT_STRING, expense.getAmount());
    xml.AddElem(DATE_STRING, expense.getDate());
    xml.OutOfElem();
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
    expense.setDate(expenseDate);

    return expense;
}


void FileWithExpenses::addExpense(int loggedUserId, vector <Expense> &expenses)
{
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    Expense newExpense = enterDataForNewExpense(loggedUserId);
    expenses.push_back(newExpense);
    saveExpenseToFile(newExpense);
    cout << "Expense added";
}
