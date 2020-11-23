#include "ControlClass.h"

void ControlClass::userRegistration()
{
    userManager.userRegistration();
}

void ControlClass::userLogin()
{
    userManager.userLogin();
    if(userManager.isTheUserLogedIn())
    {
        financeManager=new FinanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLogedUserID());
    }
}

void ControlClass::userLogout()
{
    userManager.userLogout();
}

void ControlClass::changePassword()
{
    userManager.changePassword();
}

int ControlClass::getLogedUserID()
{
    userManager.getLogedUserID();
}

void ControlClass::showAllUsers()
{
    userManager.showAllUsers();
}

bool ControlClass::isTheUserLogedIn()
{
    return userManager.isTheUserLogedIn();
}

int ControlClass::whatDayIsToday()
{
    return timeManager.whatDayIsToday();
}

void ControlClass::addNewIncome()
{
    financeManager->addNewIncome();
}

void ControlClass::addNewExpense()
{
    financeManager->addNewExpense();
}

void ControlClass::checkBalanceForCurrentMonth()
{
    financeManager->checkBalanceForCurrentMonth();
}

void ControlClass::checkBalanceForLastMonth()
{
    financeManager->checkBalanceForLastMonth();
}

void ControlClass::checkBalanceForCustomPeroid()
{
    financeManager->checkBalanceForCustomPeroid();
}

void ControlClass::showAllIncomes()
{
    financeManager->showAllIncomes();
}

void ControlClass::showAllExpenses()
{
    financeManager->showAllExpenses();
}

char ControlClass::selectOptionsFromTheMainMenu()
{
    char choice;
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|==============MY FINANCE============|"<<endl;
    cout<<"|______________main menu_____________|"<<endl;
    cout<<"| 1. Registration                    |"<<endl;
    cout<<"| 2. Login                           |"<<endl;
    cout<<"| 9. Quit                            |"<<endl;
    cout<<"+============================";
    cout<<whatDayIsToday();
    cout<<"+" << endl;
    cin>>choice;
    return choice;
}

char ControlClass::selectOptionsFromTheUserMenu()
{
    char choice;
    system("cls");
    cout<<"+==================KW================+"<<endl;
    cout<<"|==============MY FINANCE============|"<<endl;
    cout<<"|______________user menu_____________|"<<endl;
    cout<<"| 1. Add income                      |"<<endl;
    cout<<"| 2. Add expense                     |"<<endl;
    cout<<"| 3. Show balance for current month  |"<<endl;
    cout<<"| 4. Show balance for last month     |"<<endl;
    cout<<"| 5. Show balance for custom period  |"<<endl;
    cout<<"+====================================+"<<endl;
    cout<<"| 6. Change password                 |"<<endl;
    cout<<"| 7. Logout                          |"<<endl;
    cout<<"+====================================+"<<endl;
    cout<<"Your choice: ";
    cin>>choice;
    cout<<"+====================================+"<<endl;
    return choice;
}
