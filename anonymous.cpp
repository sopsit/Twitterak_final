#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
#include <fstream>
#include"User.h"
#include "Date.h"
#include"Anonymous.h"

using namespace std;

Anonymous :: Anonymous()      // constructor
{
    set_name("Anonymous User");
}

/////////////////////////////////////////////////////////////

string Anonymous:: signup(string &Username , string &Password)
{
    string star="*****************************";
    string  type="null" , flag="!file cant open.";
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    int checking_username=checkusername(Username , type);
    if(checking_username==-1)  flag="This username is exist.";
    else if(checking_username==0  || checking_username==1) // 0->There is no user.
    {                                                      //1->user not found
        string set_uname=set_username(Username), set_pass= set_password(Password);
        if(set_uname=="true" && set_pass=="true")
        {
            string id=set_id(Username , "A");
            ofstream out("users_whith_pass.txt" , ios::app);
            if(out.is_open()==true)
            {
                out<<id<<"\n"<<get_password()<<"\n"<<star<<"\n";
                out.close();
                if(add_to_follow(id)==true)  // add user to following_followers file
                    flag="! You have successfully signed up.";
            }
        }
        else if(set_uname!="true") flag=set_uname;
        else if(set_pass!="true")  flag=set_pass;
    }
    return flag;
}

////////////////////////////////////////////////////////////////////////////////

string Anonymous:: add_tweet(string &Username , string &Text)
{
    return "!This option is not available for you. ";
}

/////////////////////////////////////////////////////////////////////////////////

string Anonymous:: edit_name(string &Username ,const  string &new_name)
{
    return "!This option is not available for you. ";
}

///////////////////////////////////////////////////////////////////////////////

string Anonymous:: edit_link_country_color(string &Username , string &new_item , string type)
{
    return "!This option is not available for you. ";
}

////////////////////////////////////////////////////////////////////////////////

string  Anonymous:: edit_phonenumber(string &Username , string &new_phone)
{
    return "!This option is not available for you. ";
}

/////////////////////////////////////////////////////////////////////////////////

string Anonymous::  edit_bio(string &Username , string &new_bio)
{
    return "!This option is not available for you. ";
}

////////////////////////////////////////////////////////////////////////////////

string Anonymous:: edit_date(string &Username , string &new_date)
{
    return "!This option is not available for you. ";
}

///////////////////////////////////////////////////////////////////////////////

string Anonymous:: edit_Organization_Username(string &Username , string &new_organization_Username)
{
    return "!This option is not available for you. ";
}

///////////////////////////////////////////////////////////////////////////////

string Anonymous:: edit_organization1_Username(string &Username , string &new_organization_Username)
{
    return "!This option is not available for you. ";
}

///////////////////////////////////////////////////////////////////////////////////

string Anonymous:: retweet_or_qotetweet(string &Username,string &User_retweet,const string &tweet_num,
                                       string Text)
{
    return "!This option is not available for you. ";
}

///////////////////////////////////////////////////////////////////////////////////

string Anonymous:: add_mention (string &Username1 , string &User_mention1 , string &Text1 , string &tweet_number1)
{
    string star="*****************************", Line="------------------------------";
    string flag="!File cant open" , uname , text="null" ;
    if(Username1[0]=='@') Username1=Username1.substr(1); Username1=ToLower(Username1);
    if(User_mention1[0]=='@') User_mention1=User_mention1.substr(1); User_mention1=ToLower(User_mention1);
    string id=get_id(Username1) , id_mention=get_id(User_mention1);
    bool flag1=false , flag2=false ;
    if(id!="no user found." && id!="not found.", id_mention!="no user found." && id_mention!="not found.")
    {
        ifstream in("following_followers.txt");
        if(in.is_open()==true)
        {
            while(in>>uname)     // validation to know this user follow this account or no
            {
                while(text!=star)
                {
                    in>>text;
                    if(uname==id_mention&& text=="following")
                    {
                        flag1=true;
                        while(text!=Line)
                        {
                           // cout<<text<<"   ";
                            if(id==text) // This indicates that this user is following
                            {
                             //   cout<<text;
                                flag2=true; break;
                            }
                            in>>text;
                        }
                    }
                }
                if(flag1==true) break;
                else text="null";
            }
            in.close();
            if(flag2==true) flag=User::add_mention(Username1 , User_mention1 , Text1 , tweet_number1);
            else flag="!You should first follow this account.";
        }
        else flag="!File cant open.";
    }
    else flag="!User not found.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////////////

string Anonymous:: add_like_tweet(string &Username1 , string &User_like1 , string &tweet_number1)
{
    string star="*****************************",Line="------------------------------";
    string flag="!File cant open" , uname , text="null" ;
    if(Username1[0]=='@') Username1=Username1.substr(1); Username1=ToLower(Username1);
    if(User_like1[0]=='@') User_like1=User_like1.substr(1); User_like1=ToLower(User_like1);
    string id=get_id(Username1) , id_mention=get_id(User_like1);
    bool flag1=false , flag2=false ;
    if(id!="no user found." && id!="not found.", id_mention!="no user found." && id_mention!="not found.")
    {
        ifstream in("following_followers.txt");
        if(in.is_open()==true)
        {
            while(in>>uname)    // validation to know this user follow this account or no
            {
                while(text!=star)
                {
                    in>>text;
                    if(uname==id_mention && text=="following")
                    {
                        flag1=true;
                        while(text!=Line)
                        {
                            if(id==text) // This indicates that this user is following
                            {
                                flag2=true; break;
                            }
                            in>>text;
                        }
                    }
                }
                if(flag1==true) break;
                else text="null";
            }
            in.close();
            if(flag2==true) flag=User::add_like_tweet(Username1 , User_like1 , tweet_number1);
            else flag="!You should first follow this account.";
        }
        else flag="!File cant open.";
    }
    else flag="!User not found.";
    return flag;
}

/////////////////////////////////////////////////////////////////////////////////////
