#include "IncomesManager.h"

void IncomesManager::showAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            wyswietlDaneIncomea(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
}

void IncomesManager::wyswietlDaneIncomea(Income income)
{
    cout << endl;
    cout << "Id:                 " << income.getId() << endl;
    cout << "Imie:               " << income.getName()<< endl;
    cout << "Nazwisko:           " << income.getSurname() << endl;
    cout << "Numer telefonu:     " << income.getPhoneNumber() << endl;
    cout << "Email:              " << income.getEmail() << endl;
    cout << "Adres:              " << income.getAddress() << endl;
}

void IncomesManager::addIncome()
{
    fileWithIncomes.addIncome(ID_ZALOGOWANEGO_UZYTKOWNIKA, incomes);
}

int IncomesManager::podajIdWybranegoIncomea()
{
    int chosenIncomeId = 0;
    cout << "Podaj numer ID Incomea: ";
    chosenIncomeId  = AdditionalFunctions::getIntNumber();
    return chosenIncomeId;
}

void IncomesManager::removeIncome()
{
    int IncomeBeingRemovedId = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    IncomeBeingRemovedId = podajIdWybranegoIncomea();

    char znak;
    bool checkIfIncomeEists = false;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getId() == IncomeBeingRemovedId)
        {
            checkIfIncomeEists = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = AdditionalFunctions::getChar();
            if (znak == 't')
            {
                incomes.erase(itr);
                fileWithIncomes.removeIncomeZPliku(IncomeBeingRemovedId);
                cout << endl << endl << "Szukany income zostal USUNIETY" << endl << endl;
            }
            else
            {
                cout << endl << endl << "Wybrany income NIE zostal usuniety" << endl << endl;
            }
            break;
        }
    }
    if (checkIfIncomeEists == false)
    {
        cout << endl << "Nie ma takiego incomea w ksiazce adresowej" << endl << endl;
    }
}

char IncomesManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = AdditionalFunctions::getChar();

    return wybor;
}

void IncomesManager::editIncome()
{
    system("cls");
    Income income;
    int idEdytowanegoIncomea = 0;
    string lineWithIncomeData = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoIncomea = podajIdWybranegoIncomea();

    char wybor;
    bool checkIfIncomeEists = false;

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getId() == idEdytowanegoIncomea)
        {
            checkIfIncomeEists = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
                case '1':
                    cout << "Podaj nowe name: ";
                    incomes[i].setName(AdditionalFunctions::getLine());
                    incomes[i].setName(AdditionalFunctions::makeFirstLetterBig(incomes[i].getName()));
                    fileWithIncomes.updateChosenIncomeData(incomes[i]);
                    break;
                case '2':
                    cout << "Podaj nowe surname: ";
                    incomes[i].setSurname(AdditionalFunctions::getLine());
                    incomes[i].setSurname(AdditionalFunctions::makeFirstLetterBig(incomes[i].getSurname()));
                    fileWithIncomes.updateChosenIncomeData(incomes[i]);
                    break;
                case '3':
                    cout << "Podaj nowy numer telefonu: ";
                    incomes[i].setPhoneNumber(AdditionalFunctions::getLine());
                    fileWithIncomes.updateChosenIncomeData(incomes[i]);
                    break;
                case '4':
                    cout << "Podaj nowy email: ";
                    incomes[i].setEmail(AdditionalFunctions::getLine());
                    fileWithIncomes.updateChosenIncomeData(incomes[i]);
                    break;
                case '5':
                    cout << "Podaj nowy adres zamieszkania: ";
                    incomes[i].setAddress(AdditionalFunctions::getLine());
                    fileWithIncomes.updateChosenIncomeData(incomes[i]);
                    break;
                case '6':
                    cout << endl << "Powrot do menu usera" << endl << endl;
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu! Powrot do menu usera." << endl << endl;
                    break;
            }
            break;
        }
    }
    if (checkIfIncomeEists == false)
    {
        cout << endl << "There is no such a income" << endl << endl;
    }
}

