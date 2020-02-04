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

void Finances::addIncome(int loggedUserId)
{
    incomesManager -> addIncome();
}

void Finances::addExpense(int loggedUserId)
{
    expensesManager -> addExpense();
}

void Finances::showCurrentMonthBalance()
{
    int firstDayOfMonth = AdditionalFunctions::convertDateFromStringToInt(AdditionalFunctions::getCurrentYear() + AdditionalFunctions::getCurrentMonth() + "01");
    int lastDayOfMonth = AdditionalFunctions::convertDateFromStringToInt(AdditionalFunctions::getCurrentYear() + AdditionalFunctions::getCurrentMonth() + "31");
    vector <Income> expectedIncomes = incomesManager -> prepareIncomesBasedOnDate(firstDayOfMonth, lastDayOfMonth);
    vector <Expense> expectedExpenses = expensesManager -> prepareExpensesBasedOnDate(firstDayOfMonth, lastDayOfMonth);
    incomesManager -> showIncomes(expectedIncomes);
    expensesManager -> showExpenses(expectedExpenses);
}

void Finances::showPreviousMonthBalance()
{
    int firstDayOfMonth = AdditionalFunctions::convertDateFromStringToInt(AdditionalFunctions::getYearFromLastYearMonth() + AdditionalFunctions::getPreviousMonth() + "01");
    int lastDayOfMonth = AdditionalFunctions::convertDateFromStringToInt(AdditionalFunctions::getYearFromLastYearMonth() + AdditionalFunctions::getPreviousMonth() + "31");
    vector <Income> expectedIncomes = incomesManager -> prepareIncomesBasedOnDate(firstDayOfMonth, lastDayOfMonth);
    vector <Expense> expectedExpenses = expensesManager -> prepareExpensesBasedOnDate(firstDayOfMonth, lastDayOfMonth);
    incomesManager -> showIncomes(expectedIncomes);
    expensesManager -> showExpenses(expectedExpenses);
}

void Finances::showBalanceFromSpecifiedPeriod()
{


    cout << "Type starting date:";
    string startingDate;
    cin >> startingDate;
    cout << endl;
    while(!AdditionalFunctions::checkIfDateIsValid(startingDate))
    {
        cout << "Date invalid. Type one more time: "<< endl;
        cin >> startingDate;
    }


    cout << "Type ending date:";
    string endingDate;
    cin >> endingDate;
    cout << endl;
    while(!AdditionalFunctions::checkIfDateIsValid(endingDate))
    {
        cout << "Date invalid. Type one more time: "<< endl;
        cin >> endingDate;
    }


    vector <Income> expectedIncomes = incomesManager -> prepareIncomesBasedOnDate(AdditionalFunctions::convertDateFromStringToInt(startingDate), AdditionalFunctions::convertDateFromStringToInt(endingDate));
    vector <Expense> expectedExpenses = expensesManager -> prepareExpensesBasedOnDate(AdditionalFunctions::convertDateFromStringToInt(startingDate), AdditionalFunctions::convertDateFromStringToInt(endingDate));
    incomesManager -> showIncomes(expectedIncomes);
    expensesManager -> showExpenses(expectedExpenses);
}
