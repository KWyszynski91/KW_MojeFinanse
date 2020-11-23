#include "FinanceManager.h"

Incomes FinanceManager::getNewIncomeData()
{
    Incomes income;

    string item="";
    int operationDate=0;
    float amount=0;
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeID()+1);
    income.setUserId(LOGED_USER_ID);

    cout<<"When the income came ?"<<endl;
    cout<<"(1) Enter TODAY'S DATE"<<endl;
    cout<<"(2) Enter DIFFERENT DATE"<<endl;
    cin>>choice;
    switch(choice)
            {
            case '1':
                operationDate=timeManager.whatDayIsToday();
                break;
            case '2':
                operationDate=timeManager.readTheDate();
                break;
            default:
                    cout<<endl<<"No option in menu." <<endl<<endl;
                system("pause");
                break;
            }
    income.setDate(operationDate);

    cout << "Describe income: ";
    item=AuxiliaryMethods::loadLine();
    item=AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(item);

    cout << "Enter the value of item: ";
    cin>>amount;

    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void FinanceManager::addNewIncome()
{
    Incomes income;
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|==============MY FINANCE============|"<<endl;
    cout<<"|____________add new income__________|"<<endl;
    income=getNewIncomeData();

    theIncomes.push_back(income);
    incomesFile.saveIncomeToFile(income);
    system("pause");
}

Expenses FinanceManager::getNewExpenseData()
{
    Expenses expense;

    string item="", strAmount="";
    int operationDate=0;
    float amount=0;
    char choice;

    expense.setExpenseId(expensesFile.getLastExpenseID()+1);
    expense.setUserId(LOGED_USER_ID);

    cout<<"When the expense came out ?"<<endl;
    cout<<"(1) Enter TODAY'S DATE"<<endl;
    cout<<"(2) Enter DIFFERENT DATE"<<endl;
    cin>>choice;
    switch(choice)
            {
            case '1':
                operationDate=timeManager.whatDayIsToday();
                break;
            case '2':
                operationDate=timeManager.readTheDate();
                break;
            default:
                    cout<<endl<<"No option in menu." <<endl<<endl;
                system("pause");
                break;
            }
    expense.setDate(operationDate);

    cout << "Describe expense: ";
    item=AuxiliaryMethods::loadLine();
    item=AuxiliaryMethods::changeFirstLetterToLargeAndRestToSmall(item);

    cout << "Enter the value of item: ";
    cin>>strAmount;
    amount=AuxiliaryMethods::changeCommaToDot(strAmount);

    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void FinanceManager::addNewExpense()
{
    Expenses expense;
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|==============MY FINANCE============|"<<endl;
    cout<<"|___________add new expense__________|"<<endl;
    expense=getNewExpenseData();

    theExpenses.push_back(expense);
    expensesFile.saveExpenseToFile(expense);
    system("pause");
}

float FinanceManager::getPeriodSumOfIncomes(vector <Incomes> thePeroidIncomes)
{
    float sumAmountInc=0;
    for(int i=0; i<thePeroidIncomes.size(); i++)
    {
            sumAmountInc+=thePeroidIncomes[i].getAmount();
    }
    return sumAmountInc;
}

float FinanceManager::getPeriodSumOfExpenses(vector <Expenses> thePeroidExpenses)
{
    float sumAmountExp=0;
    for(int i=0; i<thePeroidExpenses.size(); i++)
    {
        sumAmountExp+=thePeroidExpenses[i].getAmount();
    }

    return sumAmountExp;
}

vector <Incomes> FinanceManager::FillPeroidIncomes(int startDate, int endDate)
{
    vector <Incomes> thePeroidIncomes;
    Incomes balanceIncome;
    int bUserId=0, bIncomeId=0, bDate=0;
    float bAmount=0;
    string bItem="";
    for(int i=0; i<theIncomes.size(); i++)
    {
        if((theIncomes[i].getDate()<=endDate)&&(theIncomes[i].getDate()>=startDate))
        {
            bIncomeId=theIncomes[i].getIncomeId();
            bUserId=theIncomes[i].getUserId();
            bDate=theIncomes[i].getDate();
            bItem=theIncomes[i].getItem();
            bAmount=theIncomes[i].getAmount();

            balanceIncome.setUserId(bUserId);
            balanceIncome.setIncomeId(bIncomeId);
            balanceIncome.setDate(bDate);
            balanceIncome.setItem(bItem);
            balanceIncome.setAmount(bAmount);

            thePeroidIncomes.push_back(balanceIncome);
        }
    }
    return thePeroidIncomes;
}

vector <Expenses> FinanceManager::FillPeroidExpenses(int startDate, int endDate)
{
    vector <Expenses> thePeroidExpenses;
    Expenses balanceExpense;
    int bUserId=0, bExpense=0, bDate=0;
    float bAmount=0;
    string bItem="";
    for(int j=0; j<theExpenses.size(); j++)
    {
        if((theExpenses[j].getDate()<=endDate)&&(theExpenses[j].getDate()>=startDate))
        {
            bExpense=theExpenses[j].getExpenseId();
            bUserId=theExpenses[j].getUserId();
            bDate=theExpenses[j].getDate();
            bItem=theExpenses[j].getItem();
            bAmount=theExpenses[j].getAmount();

            balanceExpense.setUserId(bUserId);
            balanceExpense.setExpenseId(bExpense);
            balanceExpense.setDate(bDate);
            balanceExpense.setItem(bItem);
            balanceExpense.setAmount(bAmount);

            thePeroidExpenses.push_back(balanceExpense);
        }
    }
    return thePeroidExpenses;
}

void FinanceManager::showPeroidBalance(float sumIncomes, float sumExpenses)
{
    cout<<"| Sum of all incomes :         "<<sumIncomes<<endl;
    cout<<"| Sum of all expenses :        "<<sumExpenses<<endl;
    cout<<"| Balance  :                   "<<sumIncomes-sumExpenses<<endl;
    cout<<"|====================================|"<<endl;
    system("pause");
}

void FinanceManager::checkBalanceForCurrentMonth()
{
    vector <Incomes> thePeroidIncomes;
    vector <Expenses> thePeroidExpenses;
    int currentDate=timeManager.whatDayIsToday();
    int firstDayofMonth=timeManager.returnFirstDayOfCurrentMonth(currentDate);
    float sumAmountInc=0, sumAmountExp=0;
    //WYPELNIANIE WEKTORoW
    thePeroidIncomes=FillPeroidIncomes(firstDayofMonth, currentDate);
    thePeroidExpenses=FillPeroidExpenses(firstDayofMonth, currentDate);
    //OBLICZANIE BILANSU
    sumAmountInc=getPeriodSumOfIncomes(thePeroidIncomes);
    sumAmountExp=getPeriodSumOfExpenses(thePeroidExpenses);
    //POKAZ WYNIKI
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|=======CURRENT MONTH BALANCE========|"<<endl;
    showPeroidBalance(sumAmountInc, sumAmountExp);
}

void FinanceManager::checkBalanceForLastMonth()
{
    vector <Incomes> thePeroidIncomes;
    vector <Expenses> thePeroidExpenses;
    float sumAmountInc=0, sumAmountExp=0;
    //OKREsLENIE DNI GRANICZNYCH
    int dayEndPrevMonth=timeManager.theLastDayOfPreviousMonth();
    int dayStartPrevMonth=timeManager.returnFirstDayOfCurrentMonth(dayEndPrevMonth);
    //WYPELNIANIE WEKTORoW
    thePeroidIncomes=FillPeroidIncomes(dayStartPrevMonth, dayEndPrevMonth);
    thePeroidExpenses=FillPeroidExpenses(dayStartPrevMonth, dayEndPrevMonth);
    //OBLICZANIE BILANSU
    sumAmountInc=getPeriodSumOfIncomes(thePeroidIncomes);
    sumAmountExp=getPeriodSumOfExpenses(thePeroidExpenses);
    //POKAZ WYNIKI
    system("cls");
    cout<<"+=================KW=================+"<<endl;
    cout<<"|=========LAST MONTH BALANCE=========|"<<endl;
    cout<<"|-"<<dayStartPrevMonth<<"------------------"<<dayEndPrevMonth<<"-|"<<endl;
    showPeroidBalance(sumAmountInc, sumAmountExp);
}

void FinanceManager::checkBalanceForCustomPeroid()
{
    vector <Incomes> thePeroidIncomes;
    vector <Expenses> thePeroidExpenses;
    float sumAmountInc=0, sumAmountExp=0;
    int dateStart=0, dateEnd=0;
    //OKREsLENIE DNI GRANICZNYCH
    cout<<"Enter the first day of term to checking balance. ";
    dateStart=timeManager.readTheDate();
    cout<<"Enter the last day of term to checking balance. ";
    dateEnd=timeManager.readTheDate();

    //WYPELNIANIE WEKTORoW
    thePeroidIncomes=FillPeroidIncomes(dateStart, dateEnd);
    thePeroidExpenses=FillPeroidExpenses(dateStart, dateEnd);
    //OBLICZANIE BILANSU
    sumAmountInc=getPeriodSumOfIncomes(thePeroidIncomes);
    sumAmountExp=getPeriodSumOfExpenses(thePeroidExpenses);
    //POKAZ WYNIKI
    system("cls");
    cout<<"+=================KW=================+"<<endl;
    cout<<"|======BALANCE FOR CUSTOM PEROID=====|"<<endl;
    cout<<"|-"<<dateStart<<"------------------"<<dateEnd<<"-|"<<endl;
    showPeroidBalance(sumAmountInc, sumAmountExp);
}

void FinanceManager::showAllIncomes()
{
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|==============MY INCOMES============|"<<endl;
    for (int i=0; i<theIncomes.size(); i++)
    {
        {
            cout<<endl<<"ID:              "<<theIncomes[i].getUserId()<<endl;
            cout<<"INC_ID:          "<<theIncomes[i].getIncomeId()<<endl;
            cout<<"DATE:            "<<theIncomes[i].getDate()<<endl;
            cout<<"ITEM:            "<<theIncomes[i].getItem()<<endl;
            cout<<"AMOUNT:          "<<theIncomes[i].getAmount()<<endl;
        }
    }
    system("pause");
}

void FinanceManager::showAllExpenses()
{
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|=============MY EXPENSES============|"<<endl;
    for (int i=0; i<theExpenses.size(); i++)
    {
        {
            cout<<endl<<"ID:              "<<theExpenses[i].getUserId()<<endl;
            cout<<"EXP_ID:          "<<theExpenses[i].getExpenseId()<<endl;
            cout<<"DATE:            "<<theExpenses[i].getDate()<<endl;
            cout<<"ITEM:            "<<theExpenses[i].getItem()<<endl;
            cout<<"AMOUNT:          "<<theExpenses[i].getAmount()<<endl;
        }
    }
    system("pause");
}

