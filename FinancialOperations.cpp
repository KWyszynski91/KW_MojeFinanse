#include "FinancialOperations.h"

//SETERY
    void FinancialOperations::setUserId(int newUserId)
    {
        userId=newUserId;
    }

    void FinancialOperations::setDate(int newDate)
    {
        date=newDate;
    }

    void FinancialOperations::setItem(string newItem)
    {
        item=newItem;
    }

    void FinancialOperations::setAmount(float newAmount)
    {
        amount=newAmount;
    }

    //GETERY
    int FinancialOperations::getUserId()
    {
        return userId;
    }

    int FinancialOperations::getDate()
    {
        return date;
    }

    string FinancialOperations::getItem()
    {
        return item;
    }

    float FinancialOperations::getAmount()
    {
        return amount;
    }
