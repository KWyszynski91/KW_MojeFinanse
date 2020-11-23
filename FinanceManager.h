#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "TimeManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class FinanceManager
{
    TimeManager timeManager;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    const int LOGED_USER_ID;
    vector <Incomes> theIncomes;
    vector <Expenses> theExpenses;
    vector <Incomes> thePeroidIncomes;
    vector <Expenses> thePeroidExpenses;

    Incomes getNewIncomeData();
    Expenses getNewExpenseData();
    vector <Incomes> FillPeroidIncomes(int startDate, int endDate);
    vector <Expenses> FillPeroidExpenses(int startDate, int endDate);
    float getPeriodSumOfIncomes(vector <Incomes> thePeroidIncomes);
    float getPeriodSumOfExpenses(vector <Expenses> thePeroidExpenses);
public:
    FinanceManager(string incomesFileName, string expensesFileName, int logedUserId):
        incomesFile(incomesFileName), expensesFile(expensesFileName), LOGED_USER_ID(logedUserId)
    {
        theIncomes=incomesFile.loadIncomesForLogedUserFromFile(LOGED_USER_ID);
        theExpenses=expensesFile.loadExpensesForLogedUserFromFile(LOGED_USER_ID);
    };
    void addNewIncome();
    void addNewExpense();
    void checkBalanceForCurrentMonth();
    void showPeroidBalance(float sumIncomes, float sumExpenses);
    void checkBalanceForLastMonth();
    void checkBalanceForCustomPeroid();
    void showAllIncomes();
    void showAllExpenses();
};

#endif
