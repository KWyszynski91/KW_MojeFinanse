#include "UserFile.h"

void UserFile::appendUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );      //WCZYTAJ PLIK "users.xml"

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();                                 //ZNAJDZ ELEMENT "Users"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "Users"
    xml.AddElem("User");                            //DODAJ ELEMENT "User"
    xml.IntoElem();                                 //PRACUJ NA GALEZI: "User"
    xml.AddElem("UserId", user.getUserId());             //DODAJ ELEMENT "UserId"
    xml.AddElem("Login", user.getLogin());               //DODAJ ELEMENT "Login"
    xml.AddElem("Password", user.getPassword());         //DODAJ ELEMENT "Password"
    xml.AddElem("User_name", user.getName());            //DODAJ ELEMENT "User_name"
    xml.AddElem("User_surname", user.getSurname());      //DODAJ ELEMENT "User_surname"
    xml.Save("users.xml");
}

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> theUsers;
    int UserId=0;
    string strUserId="", strLogin="", strPassword="", strUserName="", strUserSurname="";
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    xml.ResetPos();                             //NAGLOWERK DOKUMENTU
    xml.FindElem();                             //ZNAJDZ ELEMENT "Users"
    xml.IntoElem();                             //PRACUJ NA GALEZI: "Users"

    while (xml.FindElem("User"))                //SCZYTUJ W PETLI KOLEJNE PORCJE DANYCH "User"
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        strUserId=xml.GetData();
        UserId=AuxiliaryMethods::stringToIntConversion(strUserId);
        xml.FindElem("Login");
        strLogin=xml.GetData();
        xml.FindElem("Password");
        strPassword=xml.GetData();
        xml.FindElem("User_name");
        strUserName=xml.GetData();
        xml.FindElem("User_surname");
        strUserSurname=xml.GetData();
        xml.OutOfElem();

        user.setUserId(UserId);                     //ZAPISZ UZYSKANE DANE Z PLIKU DO WEKTORA
        user.setLogin(strLogin);
        user.setPassword(strPassword);
        user.setName(strUserName);
        user.setSurname(strUserSurname);

        theUsers.push_back(user);
    }
    return theUsers;
}
