#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesOfLoggedUser(int loggedUserId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;
    if(xml.Load( MCD_T(getFileName().c_str())))
    {
        xml.FindElem(); // INCOME element is root
        xml.IntoElem(); // inside ORDER
        while( xml.FindElem(INCOME_STRING))
        {
            xml.FindChildElem(INCOME_ID_STRING);
            int readedIncomeId = AdditionalFunctions::fromStringToInt(xml.GetChildData());
            if(readedIncomeId > lastIncomeId)
                lastIncomeId = readedIncomeId;
            income.setId(readedIncomeId);
            xml.FindChildElem(USER_ID_STRING);
            income.setUserId(AdditionalFunctions::fromStringToInt(xml.GetChildData()));
            xml.FindChildElem(TITLE_STRING);
            income.setTitle(xml.GetChildData());
            xml.FindChildElem(AMOUNT_STRING);
            income.setAmount(xml.GetChildData());
            xml.FindChildElem(DATE_STRING);
            income.setDate(AdditionalFunctions::convertDateFromStringToInt(xml.GetChildData()));
            incomes.push_back(income);
        }
    }

    return incomes;
}

void FileWithIncomes::saveIncomesToFile(const vector <Income> &incomes)
{
    CMarkup xml;
    xml.AddElem(INCOMES_STRING);
    xml.IntoElem();
    for(vector<Income>::const_iterator it = incomes.begin(); it != incomes.end(); ++it)
    {
        xml.AddElem(INCOME_STRING);
        xml.IntoElem();
        xml.AddElem(INCOME_ID_STRING, it -> getId());
        xml.AddElem(USER_ID_STRING, it -> getUserId());
        xml.AddElem(TITLE_STRING, it -> getTitle());
        xml.AddElem(AMOUNT_STRING, it -> getAmount());
        xml.AddElem(DATE_STRING, AdditionalFunctions::convertDateFromIntToString(it -> getDate()));
        xml.OutOfElem();
    }
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

    income.setDate(AdditionalFunctions::convertDateFromStringToInt(incomeDate));

    return income;
}


void FileWithIncomes::addIncome(int loggedUserId, vector <Income> &incomes)
{
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    Income newIncome = enterDataForNewIncome(loggedUserId);
    incomes.push_back(newIncome);
    sort(incomes.begin(), incomes.end());
    saveIncomesToFile(incomes);
    cout << "Income added";
}
