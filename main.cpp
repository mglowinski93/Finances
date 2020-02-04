#include <iostream>
#include <windows.h>
#include "Finances.h"
#include "UsersManager.h"
#include "AdditionalFunctions.h"

using namespace std;

const int TIME_TO_SLEEP = 2000;

int main()
{
    Finances finances("Users.xml", "Incomes.xml", "Expenses.xml");
    User loggedUser;
    char choice;
    while(true)
    {
        system("cls");
        if(loggedUser.getId() < 0)
        {
            choice = AdditionalFunctions::chooseOptionFromMainMenu();
            switch (choice)
            {
            case '1':
                finances.registerUser();
                break;
            case '2':
                loggedUser = finances.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu" << endl << endl;
                break;
            }
        }else
        {
            choice = AdditionalFunctions::chooseOptionFromUserMenu();
            switch (choice)
            {
            case '1':
                finances.addIncome(loggedUser.getId());
                break;
            case '2':
                finances.addExpense(loggedUser.getId());
                break;
            case '3':
                finances.showCurrentMonthBalance();
                break;
            case '4':
                finances.showPreviousMonthBalance();
                break;
            case '5':
                finances.showBalanceFromSpecifiedPeriod();
                break;
            case '7':
                finances.changePasswordOfLoggedUser(loggedUser);
                break;
            case '8':
                loggedUser = finances.logoutUser();
                break;
            default:
                cout << endl << "There is no such option in menu" << endl << endl;
                break;
            }
        }
        Sleep(TIME_TO_SLEEP);
    }
    return 0;

}
