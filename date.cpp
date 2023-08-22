#include "date.h"

#include<ctime>
#include <iostream>
#include <string>
//#include "Twitterak.hpp"
//#include "User.hpp"
//#include "Tweets.hpp"
#include <stdlib.h>
#include <sstream>
#include <iomanip>



using namespace std;


date:: date ()        // counstructor
{
    day=0;
    month=0;
    year=0;
}

///////////////////////////////////////////////////////////////////
int  date :: number (string input)               //change string to int
{
    int number=0;
    int size=input.size();
    for (int i=0 ; i < size  ; i++)
    {
        if (input[i] >='0' && input[i] <= '9')
            number=(number*10)+(input[i]-'0');
    }
    return number;
}

///////////////////////////////////////////////////////////////////

bool date :: set_day(int Day)
{
    bool flag=false;
    if (Day >= 1 && Day <= 31)
    {
        day=Day;
        flag=true;
    }
    return flag;
}

///////////////////////////////////////////////////////////////////

bool date :: set_month(int Month)
{
    bool flag=false;
    if (Month >= 1 && Month <= 12)
    {
        month=Month;
        flag=true;
    }
    return flag;
}

///////////////////////////////////////////////////////////////////

bool date :: set_year(int Year)
{
    bool flag=false;
    if ( Year > 0 && Year < 2023)
    {
        year=Year;
        flag=true;
    }
    return flag;
}
///////////////////////////////////////////////////////////////////

bool  date :: setdate (string &Date)
{
    bool flag=false;
    if( Birthdaydate.size()!=0)  Birthdaydate.clear();
    string temp;
    int charcter=0 , count=0 , size=Date.size();
    for(int i=0 ; i<size ; i++)
    {
        if(Date[i]!=' ')
        {
            if((Date[i] < '0' || Date[i] > '9' ) && Date[i]!='/' )charcter++;
            if (Date[i]=='/')  count++;
        }
    }
    if(charcter==0 && count==2)                       //validation for date
    {
        stringstream DATE(Date);                       // seprete date from '/'
        while(!DATE.eof())
        {
            getline(DATE, temp , '/');
            Birthdaydate.push_back(temp);
        }
        if(Birthdaydate.size()==3)
        {
            int Day , Month , Year;
            Day=number(Birthdaydate[0]);
            Month=number(Birthdaydate[1]);
            Year=number(Birthdaydate[2]);
            if (set_day(Day)==true && set_month(Month)==true && set_year(Year)==true)
            {
                flag=true;
            }
        }
    }
    if (flag==false)
    {
        day=0;
        month=0;
        year=0;
    }
    return flag;
}

///////////////////////////////////////////////////////////////////

int date ::  get_age () const //To check the legal age
{
    int age=0;
    if(year!=0)
    {
        age=2023-year;
    }
    return age;
}

///////////////////////////////////////////////////////////////////

string date ::  get_date() const
{
    string DATE="0/0/000";
    if(day!=0 && month!=0 && year!=0)
    {
        ostringstream output;
        output << setfill('0') << setw(2) << day << "/" <<  setw(2) << month << "/" <<  setw(4) << year;
        DATE=output.str();
    }
    return DATE;
}
