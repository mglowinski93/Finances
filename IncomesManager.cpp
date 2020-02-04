#include "IncomesManager.h"

void IncomesManager::showIncome(const Income income)
{
    cout << income.getTitle() << " at " << AdditionalFunctions::convertDateFromIntToString(income.getDate()) << " for " << income.getAmount() << " amount" << endl;
}

void IncomesManager::showIncomes(const vector <Income> &incomesToShow)
{
    for(vector<Income>::const_iterator it = incomesToShow.begin(); it != incomesToShow.end(); ++it)
    {
        showIncome(*it);
    }
}

void IncomesManager::addIncome()
{
    fileWithIncomes.addIncome(LOGGED_USER_ID, incomes);
}

vector <Income> IncomesManager::prepareIncomesBasedOnDate(int lowerDate, int upperDate)
{
     vector <Income> incomesWithinDate;

    for(vector<Income>::iterator it = incomes.begin(); it != incomes.end(); ++it)
    {
        if(LOGGED_USER_ID == it-> getUserId() && it -> getDate() <= upperDate && it -> getDate() >= lowerDate)
            incomesWithinDate.push_back(*it);
    }
    return incomesWithinDate;
}


float IncomesManager::calculateSumOfIncomes(const vector <Income> &incomesToSum)
{
    float sum =0;
    for(vector<Income>::const_iterator it = incomesToSum.begin(); it != incomesToSum.end(); ++it)
    {
        sum = sum + atof(it->getAmount().c_str());
    }
    return sum;
}

