#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include "FinancialOperations.h"

using namespace std;

class Incomes: public FinancialOperations
{
    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif
