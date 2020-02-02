#ifndef FILE_WITH_INCOMES_H
#define FILE_WITH_INCOMES_H

#include "Income.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "AdditionalFunctions.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
    private:
        string INCOMES_STRING = "INCOMES";
        string INCOME_STRING = "INCOME";
        string INCOME_ID_STRING = "INCOME_ID";
        string USER_ID_STRING = "USER_ID";
        string TITLE_STRING = "TITLE";
        string AMOUNT_STRING = "AMOUNT";
        string DATE_STRING = "DATE";
        int lastIncomeId;
        void saveIncomesToFile(const vector <Income> &incomes);
        Income enterDataForNewIncome(int);

    public:
        FileWithIncomes(string fileName) : XmlFile(fileName), lastIncomeId(0){};
        vector <Income> loadIncomesOfLoggedUser(int loggedUserId);
        void addIncome(int loggedUserId, vector <Income> &incomes);
};

#endif
