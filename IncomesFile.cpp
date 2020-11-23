#include "IncomesFile.h"

void IncomesFile::saveIncomeToFile(Incomes income)
{
    float amount=income.getAmount();
    string strAmount=AuxiliaryMethods::floatToStringConversion(amount);
    CMarkup xml;
    bool fileExists = xml.Load(FileName);      //WCZYTAJ PLIK "incomes.xml"

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();                                 //ZNAJDZ ELEMENT "Incomes"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "Incomes"
    xml.AddElem("Income");                          //DODAJ ELEMENT "Income"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "Income"
    xml.AddElem("IncomeId", income.getIncomeId());  //DODAJ ELEMENT "IncomeId"
    xml.AddElem("UserId", income.getUserId());      //DODAJ ELEMENT "UserId"
    xml.AddElem("Date", income.getDate());          //DODAJ ELEMENT "Date"
    xml.AddElem("Item", income.getItem());          //DODAJ ELEMENT "Item"
    xml.AddElem("Amount", strAmount);                //DODAJ ELEMENT "Amount"
    xml.Save(FileName);

    lastIncomeID++;
}

int IncomesFile::getLastIncomeID()
{
    return lastIncomeID;
}

vector <Incomes> IncomesFile::loadIncomesForLogedUserFromFile(int logedUserID)
{
    vector <Incomes> theIncomes;
    Incomes income;
    int incomeId=0, userId=0, date, foundUser=0;
    float amount=0;
    string strIncomeId="", strUserId="", strDate="", strItem="", strAmount="";

    CMarkup xml;
    bool fileExists = xml.Load(FileName);
    xml.ResetPos();                             //NAGLOWERK DOKUMENTU
    xml.FindElem();                             //ZNAJDZ ELEMENT "Incomes"
    xml.IntoElem();                             //PRACUJ NA GALEZI: "Incomes"


    while (xml.FindElem("Income"))                //ZA KAZDYM NAPOTKANYM ELEMENTEM "Income"
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        strUserId=xml.GetData();
        foundUser=AuxiliaryMethods::stringToIntConversion(strUserId);
        if(foundUser==logedUserID)
        {
            xml.ResetMainPos();
            xml.FindElem("IncomeId");
            strIncomeId=xml.GetData();
            incomeId=AuxiliaryMethods::stringToIntConversion(strIncomeId);
            xml.FindElem("Date");
            strDate=xml.GetData();
            date=AuxiliaryMethods::stringToIntConversion(strDate);
            xml.FindElem("Item");
            strItem=xml.GetData();
            xml.FindElem("Amount");
            strAmount=xml.GetData();
            amount=AuxiliaryMethods::stringToFloatConversion(strAmount);

            income.setUserId(logedUserID);
            income.setIncomeId(incomeId);
            income.setDate(date);
            income.setItem(strItem);
            income.setAmount(amount);

            theIncomes.push_back(income);
            lastIncomeID=incomeId;
        }
        xml.OutOfElem();
    }
    return theIncomes;
}
