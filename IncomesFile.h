#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Incomes.h"
#include "TimeManager.h"

using namespace std;

class IncomesFile
{
    TimeManager timeManager;
    int lastIncomeID;
    string FileName="";

public:
    IncomesFile(string incomesFileName): FileName(incomesFileName)  {
    lastIncomeID=0;
    };
    void saveIncomeToFile(Incomes income);
    int getLastIncomeID();
    vector <Incomes> loadIncomesForLogedUserFromFile(int logedUserID);
};

#endif
