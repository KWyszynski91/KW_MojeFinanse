#include "UserManager.h"

int UserManager::setNewUserID()
{
    if (theUsers.empty()==true)
        return 1;
    else
        return theUsers.back().getUserId()+1;
}

User UserManager::setNewUserData()
{
    User user;
    user.setUserId(setNewUserID());                     //USTALANIE KOLEJNEGO NUMER "ID"
    //WPROWADZANIE IMIENIA:
    string name;
    cout << "Enter your name: ";
    cin>>name;
    user.setName(name);
    //WPROWADZANIE NAZWISKA:
    string surname;
    cout << "Enter your surname: ";
    cin>>surname;
    user.setSurname(surname);
    //WPROWADZANIE LOGINU:
    string login;
    do
    {
        cout<< "Enter login: ";
        cin>>login;
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin()) == true);      //SPRAWDZENIE W SEPCJALNEJ METODZIE CZY NOWY LOGIN JEST JUZ UZYWANY
    //WPROWADZANIE HASLA:
    string password;
    cout << "Enter the password: ";
    cin>>password;
    user.setPassword(password);

    return user;
}

bool UserManager::isLoginExist(string login)
{
    for (int i=0; i<theUsers.size(); i++)
    {
        if (theUsers[i].getLogin()==login)
        {
            cout<<endl<<"There is a user with this login! Choose another one."<<endl;
            return true;
        }
    }
    return false;
}

void UserManager::userRegistration()
{
    User user = setNewUserData();                       //STWORZENIE OBIEKTU TYPU "USER" W SPECJALNEJ METODZIE
    theUsers.push_back(user);                           //WEPCHNIECIE OBIEKTU TYPU "USER" DO WEKTORA UZYTKOWNIKOW
    userFile.appendUserToFile(user);                    //WYSLANIE OBIEKTU DO ZAPISU DO PLIKU ZEWNETRZNEGO

    cout<<endl<<"New account has been created."<<endl<<endl;
    system("pause");
}

void UserManager::userLogin()
{
   User user;
    string login="", password = "";

    cout << endl << "Enter login: ";
    login=AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = theUsers.begin();
    while (itr!=theUsers.end())
    {
        if (itr -> getLogin()==login)
        {
            for (int numberOfTests=3; numberOfTests>0; numberOfTests--)
            {
                cout << "Enter the password. You have: " << numberOfTests << " tries: ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword()==password)
                {
                    logedUserID=itr -> getUserId();
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user called >"<<login<< "<"<< endl << endl;
    system("pause");
    return;
}

void UserManager::userLogout()
{
    logedUserID=0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword=AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = theUsers.begin(); itr != theUsers.end(); itr++)
    {
        if (itr->getUserId()==logedUserID)
        {
            itr->setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    string strUserId="";
    int UserId=0;
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    xml.ResetPos();                                     //NAGLOWEK DOKUMENTU
    xml.FindElem();                                     //ZNAJDZ ELEMENT "USERS"
    xml.IntoElem();                                     //PRACUJ NA TEJ GALEZI
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        strUserId=xml.GetData();
        UserId=AuxiliaryMethods::stringToIntConversion(strUserId);
        if(UserId==logedUserID)
        {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save("users.xml");
}

bool UserManager::isTheUserLogedIn()
{
    if(logedUserID>0)
        return true;
    else
        return false;
}

int UserManager::getLogedUserID()
{
    return logedUserID;
}

void UserManager::showAllUsers()
{
    cout<<"|=====ACTIVE USERS======|"<<endl;
    for (int i=0; i<theUsers.size(); i++)
    {
        {
            cout<<endl<<"ID:           "<<theUsers[i].getUserId()<<endl;
            cout<<"LOGIN:              "<<theUsers[i].getLogin()<<endl;
            cout<<"NAME:               "<<theUsers[i].getName()<<endl;
            cout<<"SURNAME:            "<<theUsers[i].getSurname()<<endl;
            cout<<"PASSWORD:           "<<theUsers[i].getPassword()<<endl;
        }
    }
    system("pause");
}
