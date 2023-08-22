#ifndef ORGANISATION_H
#define ORGANISATION_H
#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
#include "Date.h"
#include "Personal.h"
#include"Anonymous.h"

using namespace std;


class organisation: public User{
public:
    bool set_orga_username(string   & orga_Username);
    virtual bool Set_biography(const string &Biography) override;
    virtual string  add_tweet(string &Username1 , string &Text1) override;
    string get_orga_username() const;
    string signup(string &Username,const string &Password,const string &Name,const string &Phone,
                  const string &bio,const string &Country, string &Link, string &Color ,  string &orga_Username, string &add);
    virtual string edit_name(string &Username1 ,const string &new_name1) override;
    virtual string edit_link_country_color(string &Username1 , string &new_item1 , string type1) override;
    virtual string edit_phonenumber(string &Username1 , string &new_phone1) override;
    virtual string edit_bio(string &Username , string &new_bio) override;
    virtual string edit_date(string &Username , string &new_date) override;
    virtual string edit_Organization_Username(string &Username , string &new_organization_Username) override ;
    virtual string edit_organization1_Username(string &Username , string &new_organization_Username) override;
    virtual string  add_mention (string &Username1 , string &User_mention1 , string &Text1 , string &tweet_number1)
        override;
    virtual string add_like_tweet(string &Username1 , string &User_like1 , string &tweet_number1) override;
    virtual string retweet_or_qotetweet(string &Username1,string &User_retweet1,const string &tweet_num1,string
                                                                                                                Text1="null") override;
private:
    string orga_username="---------";
};
#endif
