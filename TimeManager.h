#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class TimeManager
{

    int getYear(int timeNow);
    int getMonth(int timeNow);
    int putPartsDateTogether(int year, int month, int day);
    bool isLeapYear(int timeNow);
    bool dateFormatChecking(string date);
public:
    int whatDayIsToday();
    int readTheDate();
    int returnFirstDayOfCurrentMonth(int currentDate);
    int theLastDayOfPreviousMonth();
    string useDateFormatForFile(string date);
    int useDataFormatForVector(string dateFormFile);
};

#endif
