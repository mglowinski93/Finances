#ifndef PLIK_Z_ADRESATAMI_H
#define PLIK_Z_ADRESATAMI_H

#include "Income.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "AdditionalFunctions.h"
#include "TextFile.h"

using namespace std;

class FileWithIncomes : public TextFile
{
private:
    const string tempFileWithIncomes = "tempFileWithIncomes.txt";
    int lastIncomeId;
    Income getIncomeData(string IncomeDataSplittedVerticaly);
    int getIncomeIdFromDataSplittedWithLines(string dataSingleIncomeSplittedVerticaly);
    int getUserIdFromDataLine(string dataSingleIncomeSplittedVerticaly);
    Income enterDataForNewIncome(int loggedUserId);
    void addIncomeToFile(Income income);
public:
    FileWithIncomes(string fileName) : TextFile(fileName), lastIncomeId(0){};
    vector <Income> loadIncomesOfLoggedUser(int loggedUserId);
    void addIncome(int loggedUserId, vector <Income> &incomes);
    void removeIncomeZPliku(int IncomeBeingRemovedId);
    void updateChosenIncomeData(Income income);
};

#endif
