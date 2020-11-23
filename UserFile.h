#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class UserFile
{
public:
    UserFile(string USER_FILE_NAME) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
