#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesOfLoggedUser(int loggedUserId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;
    if(xml.Load( MCD_T(getFileName().c_str())))
    {
        int incomeId = -1;
        xml.FindElem(); // INCOME element is root
        xml.IntoElem(); // inside ORDER
        while( xml.FindElem(INCOME_STRING))
        {
            xml.FindChildElem(INCOME_ID_STRING);
            incomeId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            xml.FindChildElem(USER_ID_STRING);
            int assignedUserId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            if(loggedUserId == assignedUserId)
            {
                income.setId(incomeId);
                income.setUserId(assignedUserId);
                xml.FindChildElem(TITLE_STRING);
                income.setTitle(xml.GetChildData());
                xml.FindChildElem(AMOUNT_STRING);
                income.setAmount(xml.GetChildData());
                xml.FindChildElem(DATE_STRING);
                income.setDate(xml.GetChildData());
                incomes.push_back(income);
            }
        }
        lastIncomeId = incomeId;
    }

    return incomes;
}

void FileWithIncomes::saveIncomeToFile(const Income income)
{
    CMarkup xml;
    if (!xml.Load(getFileName().c_str()))
    {
       xml.AddElem(INCOMES_STRING);
    }else
    {
       xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem(INCOME_STRING);
    xml.IntoElem();
    xml.AddElem(INCOME_ID_STRING, income.getId());
    xml.AddElem(USER_ID_STRING, income.getUserId());
    xml.AddElem(TITLE_STRING, income.getTitle());
    xml.AddElem(AMOUNT_STRING, income.getAmount());
    xml.AddElem(DATE_STRING, income.getDate());
    xml.OutOfElem();
    xml.Save(getFileName().c_str());
}


Income FileWithIncomes::enterDataForNewIncome(int loggedUserId)
{
    Income income;

    income.setId(++lastIncomeId);
    income.setUserId(loggedUserId);

    cout << "Type title: ";
    income.setTitle(AdditionalFunctions::getLine());

    cout << "Type amount: ";
    income.setAmount(AdditionalFunctions::getAmountString());

    cout << "Is it income from today? [y/n]: ";
    string userInput;
    string incomeDate;
    cin >> userInput;
    if(userInput == "y" || userInput == "yes")
    {
        incomeDate = AdditionalFunctions::getCurrentDate();
    }else
    {
        cout << "Type date: ";
        cin >> incomeDate;
        while(!AdditionalFunctions::checkIfDateIsValid(incomeDate))
        {
            cout << "Date invalid. Type one more time: "<< endl;
            cin >> incomeDate;
        }
    }
    income.setDate(incomeDate);

    return income;
}


void FileWithIncomes::addIncome(int loggedUserId, vector <Income> &incomes)
{
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    Income newIncome = enterDataForNewIncome(loggedUserId);
    incomes.push_back(newIncome);
    saveIncomeToFile(newIncome);
    cout << "Income added";
}
