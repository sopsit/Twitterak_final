#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
#include <fstream>
#include"Organisation.h"
using namespace std;

bool organisation:: set_orga_username(string   & orga_Username )
{
    bool flag=false;
    string type="null";
    if(orga_Username[0]=='@') orga_Username=orga_Username.substr(1);
    orga_Username=ToLower(orga_Username);
    if(checkusername(orga_Username , type)==-1)
    {
        if(type=="P") // personal type
        {
            flag=true;
            orga_username=orga_Username;
        }
    }
    return flag;
}
////////////////////////////////////////////////////////////

string organisation:: get_orga_username() const
{

    return orga_username;
}

/////////////////////////////////////////////////////////////

bool organisation:: Set_biography(const string &Biography)
{
    bool flag=false;
    int size=Biography.size();
    if(size <= 1100 )
    {
        flag=true;
        User::Set_biography(Biography);
    }
    return flag;
}

/////////////////////////////////////////////////////////////

string organisation:: signup(string &Username,const string &Password,const string &Name,const string &Phone,
                            const string &bio,const string &Country, string &Link,string &Color ,  string &orga_Username, string &add)
{
    string  type="null" , flag="!file cant open."; bool set_Color=true , set_bio=true;
    string star="*****************************";
    if(Username[0]=='@') Username=Username.substr(1);
    Username=ToLower(Username);
    int checking_username=checkusername(Username ,type  );
    if(checking_username==-1)  flag="This username is exsist.";
    else if(checking_username==0  || checking_username==1)
    {
        string set_uname=set_username(Username), set_pass= set_password(Password);
        bool set_phone=set_phonenymber(Phone) , set_orga_uname=set_orga_username(orga_Username);
        set_profile(add);
        if(Color!="") set_Color=set_color(Color); if(bio!="") set_bio=organisation::Set_biography(bio);
        if(set_uname=="true" && set_pass=="true" && set_phone==true && set_orga_uname==true && set_Color==true
            && set_bio==true && Name!="")
        {
            set_name(Name) ; set_country(Country) ; set_link(Link) ;
            string id=set_id(Username , "O");
            ofstream out("users_whith_pass.txt" , ios::app);
            if(out.is_open()==true)
            {
                out<<id<<endl<<get_password()<<endl<<star<<endl;
                out.close();
            }
            ofstream out2("profiles.txt" , ios::app);
            if(out2.is_open()==true)
            {
                out2<<id<<"\n"<<get_orga_username()<<"\n"<<get_name()<<"\n"<<get_biography()<<"\n"
                     <<get_phonenumber()<<"\n"<<get_country()<<"\n"<<get_link()<<"\n"<<get_color()<<
                    "\n"<<star<<"\n";
                out2.close();
                if(add_to_follow(id)==true)
                    flag="! You have successfully signed up.";
            }
            ofstream prof("profile_pic.txt");
            if(prof.is_open()==true)
            {
                prof<<id<<endl<<add<<endl<<star<<endl;
                prof.close();
            }
        }
        else if(set_uname!="true") flag=set_uname;
        else if(set_pass!="true")  flag=set_pass;
        else if(set_phone!=true) flag="!Phone number is not correct.";
        else if(set_orga_uname!=true) flag="!The username of the boss of organization is not true.";
        else if(set_bio!=true) flag="!Biography cant be more than 1100 letters.";
        else if(set_Color!=true) flag="!Color can be red/blue/green/white/black/purple/orange";
        else if(Name=="") flag="!You must filled name.";
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////

string organisation:: add_tweet(string &Username1 , string &Text1)
{
    return User::add_tweet(Username1 , Text1);
}

//////////////////////////////////////////////////////////////////////////////

string organisation:: edit_name(string &Username1 ,const string &new_name1)
{
    return User::edit_name(Username1 , new_name1);
}

//////////////////////////////////////////////////////////////////////////////

string organisation:: edit_link_country_color(string &Username1 , string &new_item1 , string type1)
{
    return User:: edit_link_country_color(Username1 , new_item1 , type1);
}

///////////////////////////////////////////////////////////////////////////////

string  organisation:: edit_phonenumber(string &Username1 , string &new_phone1)
{
    return User:: edit_phonenumber(Username1 , new_phone1);
}

/////////////////////////////////////////////////////////////////////////////////

string organisation:: edit_bio(string &Username , string &new_bio)
{
    string  uname , flag="!file cant open." , text ;int counter;
    if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found." && id[0]!='A')
    {
        if(organisation::Set_biography(new_bio)==true)
        {
            ifstream in("profiles.txt") ; ofstream out("temp.txt");
            while(getline(in ,uname))
            {
                out<<uname<<"\n";
                if(uname==id)
                {
                    for(int i=0 ; i < 2 ; i++)
                    {
                        getline( in , text);
                        out<<text<<"\n";
                    }
                    getline( in , text) ; out<<get_biography()<<"\n";
                    if(uname[0]=='O') counter=5;
                    else counter=6;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline( in , text); out<<text<<"\n";
                    }
                }
                else
                {
                    if(uname[0]=='O') counter=8;
                    else counter=9;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline( in , text); out<<text<<"\n";
                    }
                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profiles.txt");
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while( getline( in1 , text))
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close(); flag="*successfully done.";
            }
        }
        else flag="!Your biography cant be more than 1100 words.";
    }
    else flag="!User not found.";

    return flag;
}

/////////////////////////////////////////////////////////////////////////////

string organisation:: edit_date(string &Username , string &new_date)
{
    return "!This option is not available for you. ";
}

//////////////////////////////////////////////////////////////////////////////

string organisation:: edit_Organization_Username(string &Username , string &new_organization_Username)
{
    string  uname , flag="!file cant open." , text ;int counter;
    if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found." && id[0]=='O')
    {
        if(set_orga_username(new_organization_Username)==true)
        {
            ifstream in("profiles.txt") ; ofstream out("temp.txt");
            while( getline( in , uname))
            {
                out<<uname<<"\n";
                if(uname==id)
                {
                    getline( in , text); out<<new_organization_Username<<"\n";
                    if(uname[0]=='O') counter=7;
                    else counter=8;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline( in , text);
                        out<<text<<"\n";
                    }
                }
                else
                {
                    if(uname[0]=='O') counter=8;
                    else counter=9;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline( in , text);
                        out<<text<<"\n";
                    }
                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profiles.txt");
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while( getline( in1 , text))
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close(); flag="*successfully done.";
            }
        }
        else flag="!Organization username not found.";
    }
    else flag="!User not found.";
    return flag;
}

////////////////////////////////////////////////////////////////////////////////

string organisation:: edit_organization1_Username(string &Username , string &new_organization_Username)
{
    return "!This option is not available for you. ";
}

////////////////////////////////////////////////////////////////////////////////

string organisation:: add_mention (string &Username1 , string &User_mention1 , string &Text1 , string &tweet_number1)
{
    return User:: add_mention(Username1 , User_mention1 , Text1 , tweet_number1);
}

////////////////////////////////////////////////////////////////////////////////

string organisation:: add_like_tweet(string &Username1 , string &User_like1 , string &tweet_number1)
{
    return User:: add_like_tweet(Username1 , User_like1 , tweet_number1);
}

/////////////////////////////////////////////////////////////////////////////////

string organisation:: retweet_or_qotetweet(string &Username1,string &User_retweet1,const string &tweet_num1,string
                                                                                                                  Text1)
{
    return User::retweet_or_qotetweet(Username1,User_retweet1, tweet_num1,Text1);
}

////////////////////////////////////////////////////////////////////////////////
