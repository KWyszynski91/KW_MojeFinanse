#include <iostream>
#include "Markup.h"
#include "ControlClass.h"

using namespace std;

int main()
{
    ControlClass controlClass("users.xml", "incomes.xml", "expenses.xml");
    char choice;
    while (true)
    {
        if (controlClass.isTheUserLogedIn()==false)
        {
            choice=controlClass.selectOptionsFromTheMainMenu();
            switch(choice)
                {
                case '1':
                    controlClass.userRegistration(); break;
                case '2':
                    controlClass.userLogin(); break;
                case '9':
                    exit(0); break;
                default:
                    cout<<endl<<"No option in menu." <<endl<<endl;
                system("pause");
                break;
                }
        }
        else
        {
            choice=controlClass.selectOptionsFromTheUserMenu();
            switch(choice)
            {
            case '1':
                controlClass.addNewIncome(); break;
            case '2':
                controlClass.addNewExpense(); break;
            case '3':
                controlClass.checkBalanceForCurrentMonth(); break;
            case '4':
                controlClass.checkBalanceForLastMonth(); break;
            case '5':
                controlClass.checkBalanceForCustomPeroid(); break;
            case '6':
                controlClass.changePassword(); break;
            case '7':
                controlClass.userLogout(); break;
        }
    }
    }
    return 0;
}
