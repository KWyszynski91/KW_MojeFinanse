#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include "FinancialOperations.h"

using namespace std;

class Expenses: public FinancialOperations
{
    int expenseId;

public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();
};

#endif
