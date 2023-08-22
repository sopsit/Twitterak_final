#ifndef DATE_H
#define DATE_H
#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
//#include <unordered_map>
//#include<map>
#include<vector>
using namespace std;

class date
{
public:
    date ();
    bool setdate (string &Date);
    string get_date() const;
    int  get_age () const;
private :
    int day;
    int month;
    int year;
    vector < string > Birthdaydate;
    int number (string input);
    bool set_day(int Day);
    bool set_month(int Month);
    bool set_year(int Year);
};
#endif
