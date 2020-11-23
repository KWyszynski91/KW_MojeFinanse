#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Incomes.h"

using namespace std;

class IncomesFile
{
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
