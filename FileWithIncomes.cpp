#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesOfLoggedUser(int loggedUserId)
{
    Income income;
    vector <Income> incomes;
    string dataSingleIncomeSplittedVerticaly = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, dataSingleIncomeSplittedVerticaly))
        {
            if(loggedUserId == getUserIdFromDataLine(dataSingleIncomeSplittedVerticaly))
            {
                income = getIncomeData(dataSingleIncomeSplittedVerticaly);
                incomes.push_back(income);
            }
            lastIncomeId = getIncomeIdFromDataSplittedWithLines(dataSingleIncomeSplittedVerticaly);
        }
    }
    else
        cout << "Failed to load data from file" << endl;

    textFile.close();
    return incomes;
}

Income FileWithIncomes::getIncomeData(string IncomeDataSplittedVerticaly)
{
    Income income;
    string singleIncomeData = "";
    int numberOfSingleIncomeLine = 1;

    for (int charPosition = 0; charPosition < IncomeDataSplittedVerticaly.length(); charPosition++)
    {
        if (IncomeDataSplittedVerticaly[charPosition] != '|')
        {
            singleIncomeData += IncomeDataSplittedVerticaly[charPosition];
        }
        else
        {
            switch(numberOfSingleIncomeLine)
            {
            case 1:
                income.setId(atoi(singleIncomeData.c_str()));
                break;
            case 2:
                income.setUserId(atoi(singleIncomeData.c_str()));
                break;
            case 3:
                income.setName(singleIncomeData);
                break;
            case 4:
                income.setSurname(singleIncomeData);
                break;
            case 5:
                income.setPhoneNumber(singleIncomeData);
                break;
            case 6:
                income.setEmail(singleIncomeData);
                break;
            case 7:
                income.setAddress(singleIncomeData);
                break;
            }
            singleIncomeData = "";
            numberOfSingleIncomeLine++;
        }
    }
    return income;
}

int FileWithIncomes::getIncomeIdFromDataSplittedWithLines(string dataSingleIncomeSplittedVerticaly)
{
    int pozycjaRozpoczeciaIdIncomea = 0;
    int idIncomea = AdditionalFunctions::fromStringToInt(AdditionalFunctions::getNumber(dataSingleIncomeSplittedVerticaly, pozycjaRozpoczeciaIdIncomea));
    return idIncomea;
}

int FileWithIncomes::getUserIdFromDataLine(string dataSingleIncomeSplittedVerticaly)
{
    int pozycjaRozpoczeciaIdUsera = dataSingleIncomeSplittedVerticaly.find_first_of('|') + 1;
    int userId = AdditionalFunctions::fromStringToInt(AdditionalFunctions::getNumber(dataSingleIncomeSplittedVerticaly, pozycjaRozpoczeciaIdUsera));

    return userId;
}

void FileWithIncomes::addIncome(int loggedUserId, vector <Income> &incomes)
{
    Income income;
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterDataForNewIncome(loggedUserId);
    incomes.push_back(income);
    addIncomeToFile(income);
}

Income FileWithIncomes::enterDataForNewIncome(int loggedUserId)
{
    Income income;

    income.setId(++lastIncomeId);
    income.setUserId(loggedUserId);

    cout << "Type name: ";
    income.setName(AdditionalFunctions::getLine());
    income.setName(AdditionalFunctions::makeFirstLetterBig(income.getName()));

    cout << "Type surname: ";
    income.setSurname(AdditionalFunctions::getLine());
    income.setSurname(AdditionalFunctions::makeFirstLetterBig(income.getSurname()));

    cout << "Type phone number: ";
    income.setPhoneNumber(AdditionalFunctions::getLine());

    cout << "Type email: ";
    income.setEmail(AdditionalFunctions::getLine());

    cout << "Type address: ";
    income.setAddress(AdditionalFunctions::getLine());
    return income;
}

void FileWithIncomes::addIncomeToFile(Income income)
{
    string lineWithIncomeData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        if (checkIfFileEmpty() == true)
        {
            textFile << lineWithIncomeData << endl;
        }
        else
        {
            textFile << lineWithIncomeData << endl;
        }
    }
    else
    {
        cout << "Failed to open file and save data." << endl;
    }
    textFile.close();
}

void FileWithIncomes::removeIncomeZPliku(int IncomeBeingRemovedId)
{
    fstream readTextFile, tempTextFile;
    string loadedLine = "";
    string ostatniZapisanyIncome;
    int numerWczytanejLinii = 1;

    readTextFile.open(getFileName().c_str(), ios::in);
    tempTextFile.open(tempFileWithIncomes.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true)
    {
        while (getline(readTextFile, loadedLine))
        {
            if(getIncomeIdFromDataSplittedWithLines(loadedLine) != IncomeBeingRemovedId)
            {
                tempTextFile << loadedLine <<endl;
                ostatniZapisanyIncome = loadedLine;
            }
        }
        readTextFile.close();
        tempTextFile.close();
        AdditionalFunctions::removeFile(getFileName());
        AdditionalFunctions::changeFileName(tempFileWithIncomes, getFileName());
    }
}

void FileWithIncomes::updateChosenIncomeData(Income income)
{
    fstream readTextFile, tempTextFile;
    string loadedLine = "";
    int numerWczytanejLinii = 1;

    readTextFile.open(getFileName().c_str(), ios::in);
    tempTextFile.open(tempFileWithIncomes.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true)
    {
        while (getline(readTextFile, loadedLine))
        {
            if(getIncomeIdFromDataSplittedWithLines(loadedLine) != income.getId())
            {
                //tempTextFile << loadedLine <<endl;
            }else
            {
                //tempTextFile << zamienDaneIncomeaNaLinieZDanymiOddzielonymiPionowymiKreskami(income) << endl;
            }
        }
        readTextFile.close();
        tempTextFile.close();
        AdditionalFunctions::removeFile(getFileName());
        AdditionalFunctions::changeFileName(tempFileWithIncomes, getFileName());
    }
}
