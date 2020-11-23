#include "TimeManager.h"

int TimeManager::getYear(int timeNow)
{
    int year=0;
    string dateString=AuxiliaryMethods::intToStringConversion(timeNow);
    string strYear=dateString.substr(0,4);
    year=AuxiliaryMethods::stringToIntConversion(strYear);

    return year;
}

int TimeManager::getMonth(int timeNow)
{
    int month=0;
    string dateString=AuxiliaryMethods::intToStringConversion(timeNow);
    string strMonth=dateString.substr(4,2);
    month=AuxiliaryMethods::stringToIntConversion(strMonth);

    return month;
}

int TimeManager::putPartsDateTogether(int year, int month, int day)
{
    int completeDate=0;
    string strCompleteDate="";
    string strYear="", strMonth="", strDay="";
    //ZAMIANA ZMIENNYCH INTEGER NA STRING
    strYear=AuxiliaryMethods::intToStringConversion(year);
    strMonth=AuxiliaryMethods::intToStringConversion(month);
    strDay=AuxiliaryMethods::intToStringConversion(day);
    //SKLEJENIE AKTUALNEJ DATY DO FORMATU 'STRING DATE' RRRRMMDD
    strCompleteDate.insert(0,strYear);
    if(strMonth.length()==1)
    {
        strCompleteDate.insert(4,"0");
        strCompleteDate.insert(5,strMonth);
    }
    else
    {
        strCompleteDate.insert(4,strMonth);
    }
    if(strDay.length()==1)
    {
        strCompleteDate.insert(6,"0");
        strCompleteDate.insert(7,strDay);
    }
    else
    {
        strCompleteDate.insert(6,strDay);
    }
    completeDate=AuxiliaryMethods::stringToIntConversion(strCompleteDate);
    return completeDate;
}

bool TimeManager::isLeapYear(int timeNow)
{
    int year=getYear(timeNow);
    if((year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        return true;
    else
        return false;
}

int TimeManager::theLastDayOfPreviousMonth()
{
    int currentDate=whatDayIsToday();
    int currentYear=getYear(currentDate);
    int currentMonth=getMonth(currentDate);
    int previousYear=0, previousMonth=0, lastDayPrevMon=0, theLastDay=0;
    //USTALANIE POPRZEDNIEGO MIESIACA I ROKU
    if(currentMonth==1)
    {
        previousMonth=12;
        previousYear=currentYear-1;
    }
    else
    {
        previousMonth=currentMonth-1;
        previousYear=currentYear;
    }
    //USTALANIE OSTATNIEGO DNIA W MIESIACU
    if((previousMonth==4)||(previousMonth==6)||(previousMonth==9)||(previousMonth==11))
    {
        lastDayPrevMon=30;
    }
    else if((previousMonth==2)&&(isLeapYear(currentYear)==true))
    {
        lastDayPrevMon=29;
    }
    else if((previousMonth==2)&&(isLeapYear(currentYear)==false))
    {
        lastDayPrevMon=28;
    }
    else
    {
        lastDayPrevMon=31;
    }
    theLastDay=putPartsDateTogether(previousYear, previousMonth, lastDayPrevMon);
    return theLastDay;
}

int TimeManager::whatDayIsToday()
{
    int timeNow=0;
    time_t now=time(0);
    tm *ltm = localtime(&now);
    int year=(1900 + ltm->tm_year);
    int month=(1 + ltm->tm_mon);
    int day=(ltm->tm_mday);
    int hour=(ltm->tm_hour);
    int minute=(ltm->tm_min);
    int secunde=(ltm->tm_sec);

    timeNow=putPartsDateTogether(year, month, day);
    return timeNow;
}

bool TimeManager::dateFormatChecking(string date)
{
    int stringLong=date.length();

    if(stringLong!=10)
        return false;

    string strMonth=date.substr(5,2);
    int month=AuxiliaryMethods::stringToIntConversion(strMonth);
    string strDay=date.substr(8,2);
    int day=AuxiliaryMethods::stringToIntConversion(strDay);

    if((date[4]!='-')&&(date[7]!='-'))
        return false;
    else if(month>12)
        return false;
    else if(day>31)
        return false;
    else
        return true;
}

int TimeManager::readTheDate()
{
    string loadedDate="";
    string singleData="";
    int stringLong=0, correctDate=0, year=0, month=0, day=0;
    int numberOfSingleData=1;

    cout<<"Please use format YYYY-MM-DD:"<<endl;
    while(true)
    {
        loadedDate=AuxiliaryMethods::loadLine();
        stringLong=loadedDate.length();

        if(dateFormatChecking(loadedDate)==true)
        {
            for (int signPosition=0; signPosition<=stringLong; signPosition++)
            {
                if((loadedDate[signPosition]!='-')&&(signPosition!=stringLong))
                {
                    singleData+=loadedDate[signPosition];
                }
                else
                {
                    switch(numberOfSingleData)
                    {
                    case 1:
                        year=AuxiliaryMethods::stringToIntConversion(singleData);
                        break;
                    case 2:
                        month=AuxiliaryMethods::stringToIntConversion(singleData);
                        break;
                    case 3:
                        day=AuxiliaryMethods::stringToIntConversion(singleData);
                    }
                    singleData="";
                    numberOfSingleData++;
                }
            }
            correctDate=putPartsDateTogether(year, month, day);
                return correctDate;
        }
        else
        {
            cout<<"Invalid date format. Enter correct format."<<endl;
        }
    }
}

int TimeManager::returnFirstDayOfCurrentMonth(int currentDate)
{
    string strCurrentDate=AuxiliaryMethods::intToStringConversion(currentDate);
    string strFirstOfMonth=strCurrentDate.replace(6,2,"01");
    int firstOfMonth=AuxiliaryMethods::stringToIntConversion(strFirstOfMonth);
    return firstOfMonth;
}
