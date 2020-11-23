#ifndef CONTROLCLASS_H
#define CONTROLCLASS_H

#include <iostream>
#include "UserManager.h"
#include "TimeManager.h"
#include "FinanceManager.h"

using namespace std;

class ControlClass
{
    UserManager userManager;
    TimeManager timeManager;
    FinanceManager *financeManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    ControlClass(string userFileName, string incomesFileName, string expensesFileName)
    : userManager(userFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        financeManager=NULL;
    };
    ~ControlClass() //DESTRUKTOR
    {
        delete financeManager;
        financeManager=NULL;
    }

    void userRegistration();
    void userLogin();
    void userLogout();
    void changePassword();
    int getLogedUserID();
    void showAllUsers();
    bool isTheUserLogedIn();
    int whatDayIsToday();
    void addNewIncome();
    void addNewExpense();
    void checkBalanceForCurrentMonth();
    void checkBalanceForLastMonth();
    void checkBalanceForCustomPeroid();
    char selectOptionsFromTheMainMenu();
    char selectOptionsFromTheUserMenu();
    void showAllIncomes();
    void showAllExpenses();
};

#endif
