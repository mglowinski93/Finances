#ifndef ADRESAT_MENEDZER_H
#define ADRESAT_MENEDZER_H

#include <vector>
#include "Income.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesManager
{
private:
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    void wyswietlDaneIncomea(Income income);
    int podajIdWybranegoIncomea();
    char wybierzOpcjeZMenuEdycja();
    void wyswietlIloscWyszukanychIncomeow(int iloscIncomeow);
public:
   IncomesManager(string incomeFileName, int idZalogwanegoUsera)
   : fileWithIncomes(incomeFileName), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogwanegoUsera)
   {
    incomes = fileWithIncomes.loadIncomesOfLoggedUser(ID_ZALOGOWANEGO_UZYTKOWNIKA);
   };
   void showAllIncomes();
   void addIncome();
   void removeIncome();
   void editIncome();
};

#endif
