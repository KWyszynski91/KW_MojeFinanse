#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "AuxiliaryMethods.h"
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    UserFile userFile;
    int logedUserID;
    vector <User> theUsers;
    //METODY:
    int setNewUserID();
    User setNewUserData();
    bool isLoginExist(string login);
public:
    UserManager(string userFileName): userFile(userFileName)
    {logedUserID=0;
    theUsers=userFile.loadUsersFromFile();
    };
    void userRegistration();
    void userLogin();
    void userLogout();
    void changePassword();
    void loadUsersFromFile();
    bool isTheUserLogedIn();
    int getLogedUserID();
    void showAllUsers();
};

#endif
