#ifndef USER_H
#define USER_H

#include <iostream>
#include<ctime>
#include <string>
#include <sstream>
#include<vector>
#include "Date.h"

using namespace std;

class User {
public:
    int To_int (string Number);
    string ToLower (string input);
    string set_username (string   & Username);
    string set_password (const string & Password);
    bool set_phonenymber (const string &Phonenymber);
    bool set_color ( string &color);
    void set_name (const string &Name);
    void set_country (const string &Country);
    void set_link (string &Link);
    virtual bool Set_biography(const string &Biography);
    string get_color() const;
    string get_name() const;
    string get_link() const;
    string get_username() const;
    string get_country() const;
    string get_phonenumber() const;
    string get_biography() const;
    string get_password() const;
    int checkusername (string &Username , string &type);
    string set_id(string &Username , string type);
    string get_id(string &Username);
    string get_username_id(string &Id);
    string edit_username(string &Username , string &new_Username);
    string edit_password(string &Username ,const string &new_Password);
    virtual string edit_name(string &Username ,const string &new_name);
    virtual string edit_link_country_color(string &Username , string &new_item , string type);
    virtual string edit_bio(string &Username , string &new_bio);
    virtual string edit_date(string &Username , string &new_date);
    virtual string edit_phonenumber(string &Username , string &new_phone);
    virtual string edit_Organization_Username(string &Username , string &new_organization_Username) ;
    virtual string edit_organization1_Username(string &Username , string &new_organization_Username);
    string  login (string &Username , string &Password);
    virtual string  add_tweet(string &Username , string &Text);
    virtual string  add_mention (string &username , string &user_mention , string &Text , string &tweet_number);
    string Show_tweet(string &Username);
    bool  Hashtag(string &hashtag);
    string hashtag_search(string &hashtag);
    bool check_hashtag(string &text , string &hashtag);
    bool delete_account(string &Username);
    string get_profile (string &Username , string &Color );
    string follow_unfollow(string &Username , string &Username_for_follow);
    string get_following_or_followers(string &Username , string &number , string type);
    virtual string add_like_tweet(string &Username , string &User_like , string &tweet_num);
    string add_like_mention(string &Username , string &User_like ,string &mention_num , string &tweet_num);
    virtual string retweet_or_qotetweet(string &Username,string &User_retweet,const string &tweet_num,string
                                                                                                             text="null");
    string get_profilepic_file(string username);
    string edit_profile(string &Username , string &new_address);
    string get_profilepic();
    void set_profile(string &addr);
    string  sprator(string &input);
protected:
    bool add_to_follow(string &id);
    string add_to_file(string &Id , string &Id_for_follow ,string &Followings , string &Followers , bool flag1);
    bool  add_to_likes(string &id1 , int number);
    bool   likes_dislikes(string &id1 , int &tweet_number ,string like_or_dislike);
    bool add_to_like_mention(string &Id ,  string &tweet_number1 , int &mention_num);
    bool like_dislike_mention(const string &Id ,const string &type1 , string &tweet_num1 , string &mention_num1);

private :
    string username="null";
    string name="null";
    string password="null";
    string biography="----------";
    string country="----------";
    string phonenumber="null";
    string link="----------";
    string color="null";
    string address="null";
};
#endif
