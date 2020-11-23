#include "ExpensesFile.h"

void ExpensesFile::saveExpenseToFile(Expenses expense)
{
    float amount=expense.getAmount();
    string strAmount=AuxiliaryMethods::floatToStringConversion(amount);
    CMarkup xml;
    bool fileExists = xml.Load(FileName);      //WCZYTAJ PLIK "expenses.xml"

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();                                 //ZNAJDZ ELEMENT "Expenses"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "Expenses"
    xml.AddElem("Expense");                          //DODAJ ELEMENT "Expense"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "Expense"
    xml.AddElem("ExpenseId", expense.getExpenseId());  //DODAJ ELEMENT "ExpenseId"
    xml.AddElem("UserId", expense.getUserId());      //DODAJ ELEMENT "UserId"
    xml.AddElem("Date", expense.getDate());          //DODAJ ELEMENT "Date"
    xml.AddElem("Item", expense.getItem());          //DODAJ ELEMENT "Item"
    xml.AddElem("Amount", strAmount);                //DODAJ ELEMENT "Amount"
    xml.Save(FileName);

    lastExpenseID++;
}

int ExpensesFile::getLastExpenseID()
{
    return lastExpenseID;
}

vector <Expenses> ExpensesFile::loadExpensesForLogedUserFromFile(int logedUserID)
{
    vector <Expenses> theExpenses;
    Expenses expense;
    int expenseId=0, userId=0, date=0, foundUser=0;
    float amount=0;
    string strExpenseId="", strUserId="", strDate="", strItem="", strAmount="";

    CMarkup xml;
    bool fileExists = xml.Load(FileName);
    xml.ResetPos();                             //NAGLOWERK DOKUMENTU
    xml.FindElem();                             //ZNAJDZ ELEMENT "Expenses"
    xml.IntoElem();                             //PRACUJ NA GALEZI: "Expenses"


    while (xml.FindElem("Expense"))                //ZA KAZDYM NAPOTKANYM ELEMENTEM "Expense"
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        strUserId=xml.GetData();
        foundUser=AuxiliaryMethods::stringToIntConversion(strUserId);
        if(foundUser==logedUserID)
        {
            xml.ResetMainPos();
            xml.FindElem("ExpenseId");
            strExpenseId=xml.GetData();
            expenseId=AuxiliaryMethods::stringToIntConversion(strExpenseId);
            xml.FindElem("Date");
            strDate=xml.GetData();
            date=AuxiliaryMethods::stringToIntConversion(strDate);
            xml.FindElem("Item");
            strItem=xml.GetData();
            xml.FindElem("Amount");
            strAmount=xml.GetData();
            amount=AuxiliaryMethods::stringToFloatConversion(strAmount);

            expense.setUserId(logedUserID);
            expense.setExpenseId(expenseId);
            expense.setDate(date);
            expense.setItem(strItem);
            expense.setAmount(amount);

            theExpenses.push_back(expense);
            lastExpenseID=expenseId;
        }
        xml.OutOfElem();
    }
    return theExpenses;
}
