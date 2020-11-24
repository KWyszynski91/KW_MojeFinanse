#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Expenses.h"
#include "TimeManager.h"

using namespace std;

class ExpensesFile
{
    TimeManager timeManager;
    int lastExpenseID;
    string FileName="";

public:
    ExpensesFile(string expensesFileName): FileName(expensesFileName)  {
    lastExpenseID=0;
    };
    void saveExpenseToFile(Expenses expense);
    int getLastExpenseID();
    vector <Expenses> loadExpensesForLogedUserFromFile(int logedUserID);
};

#endif
