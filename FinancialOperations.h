#ifndef FINANCIALOPERATIONS_H
#define FINANCIALOPERATIONS_H

#include <iostream>

using namespace std;

class FinancialOperations
{
    int userId;
    int date;
    string item;
    float amount;
public:
    //SETERY
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    //GETERY
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
