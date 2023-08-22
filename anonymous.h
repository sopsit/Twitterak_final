#ifndef ANONYMOUS_H
#define ANONYMOUS_H

#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
#include"User.h"

class Anonymous:public User
{

public:
    Anonymous();
    string  signup(string &Username , string &password);
    virtual string  add_tweet(string &Username , string &Text) override;
    virtual string edit_name(string &Username , const string &new_name) override;
    virtual string edit_link_country_color(string &Username , string &new_item , string type) override;
    virtual string edit_phonenumber(string &Username , string &new_phone) override;
    virtual string edit_bio(string &Username , string &new_bio) override;
    virtual string edit_date(string &Username , string &new_date) override;
    virtual string edit_Organization_Username(string &Username , string &new_organization_Username) override ;
    virtual string edit_organization1_Username(string &Username , string &new_organization_Username) override;
    virtual string  add_mention (string &Username1 , string &User_mention1 , string &Text1 , string &tweet_number1)
        override;
    virtual string add_like_tweet(string &Username1 , string &User_like1 , string &tweet_number1) override;
    virtual string retweet_or_qotetweet(string &Username,string &User_retweet,const string &tweet_num,string
                                                                                                             Text="null") override;

};

#endif
