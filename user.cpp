#include<ctime>
#include <iostream>
#include <string>
//#include "Date.h"
#include "User.h"
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include<vector>
#include <fstream>


using namespace std;

int  User :: To_int (string Number)
{
    int number=0 , size=Number.size() , character=0 ;
    for (long long int i=0 ; i<size ; i++)
    {
        if(Number[i] >= '0'  && Number[i] <= '9')
        {
            number=(number*10)+(Number[i]-'0');
        }
        else
        {
            character++;
        }
    }
    if(character!=0)
    {
        number=0;
    }

    return number;
}

//////////////////////////////////////////////////////////////////////////

string  User:: ToLower (string input)
{
    int size=input.size();
    for(int i=0 ; i<size ; i++)
    {
        if(input[i] >= 'A'  && input[i] <= 'Z')
        {
            input[i]+=32;
        }
    }
    return input;
}

//////////////////////////////////////////////////////////////////////////

string User :: set_username (string   & Username)
{
    string flag="true";
    if (Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    int size=Username.size();
    if( size < 5) flag="!Username must be at least five charactors.";
    else if(Username[0] >= '0' && Username[0] <= '9')  flag="!The first character cant be a number.";
    else if(Username=="signup" || Username=="login" || Username=="deleteaccount" || Username=="logout" ||
             Username=="tweet" || Username=="delete" ||  Username=="edit" || Username=="help" || Username=="profile" ||
             Username=="deletetweet" || Username=="editprofile" ||  Username=="retweet" ||  Username=="tweets" ||
             Username=="quote" ||  Username=="username" ||  Username=="password" ||  Username=="country" ||
             Username=="color" ||  Username=="biography" ||  Username=="account" ||  Username=="tweet" ||
             Username=="like"  ||  Username=="phonenumber" || Username=="birthdaydate" || Username=="quotetweet")
    {
        flag="!This is a reserved word.";
    }
    else
    {
        for(int i=0 ; i < size ; i++)
        {
            if((Username[i] >= ' ' && Username[i] <= '/') || (Username[i] >= ':' && Username[i] <= '@') ||
                (Username[i] >= '[' && Username[i] <= '`') || (Username[i] >= 123 && Username[i] <= '|')  )
            {
                flag="!Username must be letters or numbers.";
            }
        }
    }
    if(flag=="true") username=Username;

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User ::set_password (const string &Password)
{
    string flag="true";
    int size=Password.size() , counternum=0 , counterchar=0 , counterletter=0 ;
    if( size < 8 ) flag="!Your password must be at least eight characters.";
    else
    {
        for(int i=0 ; i < size ; i++)
        {
            if(Password[i] >= '0' && Password[i] <= '9')
            {
                counternum++;
            }
            else if((Password[i] >= 'A' && Password[i] <= 'Z') || (Password[i] >= 'a' && Password[i] <= 'z'))
            {
                counterletter++;
            }
            else if((Password[i] >= ' ' && Password[i] <= '/') || (Password[i] >= ':' && Password[i] <= '@') ||
                     (Password[i] >= '[' && Password[i] <= '`') || (Password[i] >= 123 && Password[i] <= '|')  )
            {
                counterchar++;
            }
        }
        if (counternum==0 || counterchar==0 || counterletter==0)
            flag="!Your password must be combination of english letters , numbers and characters like #.";
    }
    if (flag=="true")   password=Password;

    return flag;
}

//////////////////////////////////////////////////////////////////////////

void User :: set_name (const string &Name)
{
    if(Name!="") name=Name;
    else name="----------";
}

///////////////////////////////////////////////////////////////////////////

bool User :: Set_biography(const string &Biography)
{

    if(Biography!="") biography=Biography;
    else biography="----------";
}

//////////////////////////////////////////////////////////////////////////

void User :: set_country (const string &Country)
{
    if(Country!="") country=Country;
    else country="----------";
}

//////////////////////////////////////////////////////////////////////////

bool User :: set_phonenymber (const string  &Phonenmber)
{
    bool flag=false;
    int size=Phonenmber.size() , counter=0;
    for (int i=0 ; i < size ; i++)
    {
        if(Phonenmber[i] >= '0' && Phonenmber[i] <= '9') counter++;
    }
    if(counter==size && ( size > 11 && size < 17 ))
    {
        flag=true;
        phonenumber=Phonenmber;
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

void User :: set_link (string &Link)
{
    if(Link!="")
    {
        string LINK="https://";
        if(Link.substr( 0 , 8)=="https://")
        {
            LINK+=Link.substr(8);
            link=LINK;
        }
        else if(Link.substr( 0 , 5 )=="https")
        {
            LINK+=Link.substr(5);
            link=LINK;
        }
        else
        {
            LINK+=Link;
            link=LINK;
        }
    }
    else link="----------";
}

//////////////////////////////////////////////////////////////////////////

bool User :: set_color (string &Color)
{
    bool flag=false;
    Color=ToLower(Color);
    if(Color=="red" || Color=="yellow" || Color=="black" || Color=="orange" || Color=="blue" || Color=="purple"
        || Color=="green" ||Color=="pink")
    {
        color=Color;
        flag=true;
    }
    else
        color="whith out header color";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User :: get_username() const
{
    return username;
}

//////////////////////////////////////////////////////////////////////////

string User :: get_password() const
{
    return password;
}

//////////////////////////////////////////////////////////////////////////

string User :: get_name() const
{
    return name;
}

//////////////////////////////////////////////////////////////////////////

string User ::  get_biography() const
{
    return biography;
}

//////////////////////////////////////////////////////////////////////////

string User :: get_country() const
{
    return country;
}

//////////////////////////////////////////////////////////////////////////

string User ::  get_phonenumber() const
{
    return phonenumber;
}

//////////////////////////////////////////////////////////////////////////

string User :: get_link() const
{
    return link;
}

//////////////////////////////////////////////////////////////////////////

string  User :: get_color() const
{
    return color;
}

//////////////////////////////////////////////////////////////////////////

int User:: checkusername (string &Username , string &type)
{
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    int number=1;
    ifstream in("id.txt");
    if(!in) number=0;   // There is no user
    else
    {
        string uname , id  ;
        while(in>>uname>>id)
        {
            if(uname==Username) // Username found
            {
                number=-1;
                type=id[0];
                break;
            }
        }
        in.close();
    }
    return number;
}

//////////////////////////////////////////////////////////////////////////

string User:: set_id(string &Username , string type)
{
    int number=1;  string id="null";
    ifstream in("numbers.txt"); // The number of users is in this file
    if(!in)                    // There is no user
    {
        ofstream out("id.txt");  ofstream out1("numbers.txt");
        if(out.is_open()==true && out1.is_open()==true)
        {
            stringstream a; a<<number ; string num=a.str();
            id=type+num;                                // Type can be A/O/P
            out<<Username<<"\t"<<id<<"\n"; out.close();
            out1<<number;
            out1.close();
        }
    }
    else
    {
        in>>number ; number++;
        ofstream out("id.txt" , ios::app);
        if(out.is_open()==true)
        {
            out<<Username<<"\t"<<type<<number<<"\n"; out.close();
            in.close();
            ofstream out1("numbers.txt");
            if(out1.is_open()==true)
            {
                stringstream a; a<<number ; string num=a.str();
                id=type+num; out1<<number; out1.close();
            }
        }
    }
    return id;
}

//////////////////////////////////////////////////////////////////////////

string User:: get_id(string &Username)
{
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    string id , uname  ;
    bool flag=false;
    ifstream in("id.txt");
    if(!in) id="no user found.";
    else
    {
        while(in>>uname>>id)
        {
            if(uname==Username )
            {
                flag=true; break;
            }
        }
        if(flag!=true) id="not found.";
        in.close();
    }
    return id;
}

//////////////////////////////////////////////////////////////////////////

string User:: get_username_id(string &Id)
{
    string id , uname  ;
    bool flag=false;
    ifstream in("id.txt");
    if(!in) uname="no user found.";
    else
    {
        while(in>>uname>>id)
        {
            if(id==Id)
            {
                flag=true;
                break;
            }
        }
        if(flag!=true) uname="not found.";
        in.close();
    }
    return uname;
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_username(string &Username , string &new_Username)
{
    string  Id , uname , flag="!file cant open.";
    if(Username[0]=='@') Username=Username.substr(1);
    if(new_Username[0]=='@') new_Username=new_Username.substr(1);
    Username=ToLower(Username); new_Username=ToLower(new_Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found.") // validation to khow that username is exist or no
    {
        int checking_username=checkusername(new_Username , uname);
        if(checking_username==-1)  flag="This username is exsist.";
        if(checking_username==0)   flag="!There is no user.";
        else if(checking_username==1)
        {
            string res=set_username(new_Username);
            if(res=="true")
            {
                ifstream in("id.txt"); ofstream out("temp.txt");
                if(in.is_open()==true && out.is_open()==true)
                {
                    while(in>>uname>>Id)
                    {
                        if(Id==id) out<<new_Username<<"\t"<<id<<"\n"; // write new username in file
                        else out<<uname<<"\t"<<Id<<"\n";
                    }
                    in.close(); out.close();
                    ifstream in1("temp.txt"); ofstream out1("id.txt");
                    if(in1.is_open()==true && out1.is_open()==true)
                    {
                        while(in1>>uname>>Id)
                        {
                            out1<<uname<<"\t"<<Id<<"\n";
                        }
                        in1.close(); out1.close();
                        flag="*successfully done.";
                    }
                }
            }
            else flag=res;
        }
    }
    else flag="!User not found.";

    return flag;

}

//////////////////////////////////////////////////////////////////////////

string User:: edit_password(string &Username ,const string &new_Password)
{
    string flag="!file cant open." , text="null" ,pass , uname;
    string star="*****************************"; bool flag1=true;
    if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found.")
    {
        string res=set_password(new_Password);
        if(res=="true")
        {
            ifstream in("users_whith_pass.txt") ; ofstream out("temp.txt");
            if(in.is_open()==true && out.is_open()==true)
            {
                while(getline(in , uname))
                {
                    out<<uname<<"\n";
                    while (text!=star)
                    {
                        getline(in , text);
                        if(uname==id)
                        {
                            if(text==new_Password) flag1=false; // validation for previous passwords
                            if(text==star && flag1==true) out<<new_Password<<"\n";
                        }
                        out<<text<<"\n";
                    }
                    text="null";
                }
                in.close(); out.close();
                ifstream in1("temp.txt") ; ofstream out1("users_whith_pass.txt");
                if(out1.is_open()==true && in1.is_open()==true) //copy
                {
                    while(getline(in1 , text))
                    {
                        out1<<text<<"\n";
                    }
                    in1.close() ; out1.close();
                    if(flag1==true)  flag="*successfully done.";
                    else flag="!You cant use this password again.";
                }
            }
        }
        else flag=res;
    }
    else flag="!User not found.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_name(string &Username ,const string &new_name)
{
    string flag="!file cant open." ,uname , text ;int counter; // counters are for reading and writting correctly
    if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found." && id[0]!='A')
    {
        if(new_name!="")
        {
            set_name(new_name);
            ifstream in("profiles.txt") ; ofstream out("temp.txt");
            while(getline(in , uname))
            {
                out<<uname<<"\n";
                if(uname==id)       //username is foung
                {
                    getline(in , text); out<<text<<"\n"; //organisation username
                    getline(in , text); out<<new_name<<"\n";
                    if(uname[0]=='O') counter=6;
                    else counter=7;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline(in , text); out<<text<<"\n"; // read and write onother items
                    }
                }
                else
                {
                    if(uname[0]=='O') counter=8; // Organisation type
                    else counter=9;
                    for(int i=0 ; i < counter ; i++) // personal type
                    {
                        getline(in , text); out<<text<<"\n"; // read and write items
                    }
                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profiles.txt");
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while(getline(in1 , text)) //copy
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close();
                flag="*successfully done.";
            }
        }
        else flag="!Invalid value.";
    }
    else flag="!User not found.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_link_country_color(string &Username , string &new_item , string type)
{
    string  flag="!file cant open." , uname , text ; int counter , counter1 , counter2; bool set_Color=true;
    if(type=="color" || type=="link" || type=="country")
    {
        if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
        string id=get_id(Username);
        if(id!="no user found." && id!="not found.")
        {
            if(type=="link")        // counters are for reading and writting correctly from file
            {
                set_link(new_item) ; new_item=get_link();counter=5;
                if(id[0]=='O') counter1=2; //organisation type
                else counter1=3;
            }
            else if(type=="country")
            {
                set_country(new_item);new_item=get_country();counter=4;
                if(id[0]=='O') counter1=3;
                else counter1=4;
            }
            else if(type=="color")
            {
                set_Color=set_color(new_item); new_item=get_color(); counter=6; // validation color
                if(id[0]=='O') counter1=1;
                else counter1=2;
            }
            ifstream in("profiles.txt") ; ofstream out("temp.txt");
            while(getline(in , uname))
            {
                out<<uname<<"\n";
                if(uname==id && set_Color==true)
                {
                    for (int i=0 ; i < counter; i++)
                    {
                        getline(in , text); out<<text<<"\n"; // read another items
                    }
                    getline(in , text); out<<new_item<<"\n";
                    for(int i=0 ; i < counter1 ; i++)
                    {
                        getline(in , text);out<<text<<"\n";
                    }
                }
                else
                {
                    if(uname[0]=='O') counter2=8;
                    else counter2=9;                //personal type
                    for(int i=0 ; i < counter2 ; i++)
                    {
                        getline(in , text); out<<text<<"\n";
                    }
                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profiles.txt"); //copy
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while(getline(in1 , text ))
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close();
                if(set_Color==true) flag="*successfully done.";
                else flag="!Color is not available.";
            }
        }
        else flag="!User not found.";
    }
    else flag="!Invalid type.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_phonenumber(string &Username , string &new_phone)
{
    string  flag="!file cant open." , uname , text ; int counter;
    if(Username[0]=='@') Username=Username.substr(1) ; Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found.")
    {
        if(set_phonenymber(new_phone)==true)  // counters are for reading and writting correctly from file
        {
            ifstream in("profiles.txt") ; ofstream out("temp.txt");
            while(getline(in , uname))
            {
                out<<uname<<"\n";
                if(uname==id)
                {
                    for(int i=0 ; i < 3 ; i++)
                    {
                        getline(in , text);
                        out<<text<<"\n";
                    }
                    getline(in , text); out<<new_phone<<"\n";
                    if(uname[0]=='O') counter=4;
                    else counter=5;
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline(in , text);
                        out<<text<<"\n";
                    }
                }
                else
                {
                    if(uname[0]=='O') counter=8; // organization type
                    else counter=9;              // personal type
                    for(int i=0 ; i < counter ; i++)
                    {
                        getline(in , text); out<<text<<"\n";
                    }
                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profiles.txt");
            if(out1.is_open()==true && in1.is_open()==true) //copy
            {
                while( getline(in1 , text))
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close(); flag="*successfully done.";
            }
        }
        else flag="!Phone number is not correct.";
    }
    else flag="!User not found.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_bio(string &Username , string &new_bio)
{

}

//////////////////////////////////////////////////////////////////////////

string User:: edit_date(string &Username , string &new_date)
{

}

//////////////////////////////////////////////////////////////////////////

string User:: edit_Organization_Username(string &Username , string &new_organization_Username)
{
    // boss of organization
}

//////////////////////////////////////////////////////////////////////////

string User:: edit_organization1_Username(string &Username , string &new_organization_Username)
{
    // the name of organization
}

//////////////////////////////////////////////////////////////////////////

string User:: login (string &Username , string &Password)
{
    bool flag=false ; string id , uname , text="null" , pass ;
    string star="*****************************";
    if(Username[0]=='@') Username=Username.substr(1);
    Username=ToLower(Username);
    id=get_id(Username);
    if(id!="no user found." && id!="not found.")
    {
        ifstream in("users_whith_pass.txt");
        if(in.is_open()==true)
        {
            while(getline(in , uname ))
            {
                while (text!=star)
                {
                    getline(in , text);
                    if(uname==id)    // username is found
                    {
                        if(text!=star) pass=text;
                        if(text==star)
                        {
                            flag=true; break;
                        }
                    }
                }
                if(flag==true) break;
                text="null";
            }
            in.close();
            if(pass!=Password)  id="!Password is not correct.";
        }
    }
    else
    {
        id="!Username not found.";
    }

    return id;
}

//////////////////////////////////////////////////////////////////////////

string User:: add_tweet(string &Username , string &Text)
{
    if(Username[0]=='@') Username=Username.substr(1);  Username=ToLower(Username);
    string id=get_id(Username) , flag="file cant open.";
    if(id!="no user found." && id!="not found.")
    {
        string star="*****************************",Line="------------------------------";
        string  uname , text="null" ;   bool flag1=false ;     int tweet_num=1 ;
        ifstream in("Tweets.txt");
        if(!in)                     // No tweet found
        {
            ofstream out("Tweets.txt");
            if(out.is_open()==true)
            {                              // writting tweet in file
                out<<id<<"\n"<<"T: "<<tweet_num<<":"<<Text<<"\n"<<0<<"\n"<<Line<<"\n"<<star<<"\n";
                out.close(); flag="*successfully done.";
            }
        }
        else
        {
            ofstream out("temp.txt");
            if(out.is_open()==true)
            {
                while(getline(in , uname))
                {
                    out<<uname<<"\n";
                    while(text!=star)
                    {
                        getline(in , text);
                        if(id==uname && text.size() > 3)
                        {
                            if(text.substr(0 , 3)=="T: ") tweet_num++; // founding user tweet
                        }
                        if(id==uname && text==star)
                        {
                            flag1=true; out<<"T: "<<tweet_num<<":"<<Text<<"\n"<<0<<"\n"<<Line<<"\n"; // writting tweet in file
                        }
                        out<<text<<"\n";
                    }
                    text="null";
                }
                in.close();
                if(flag1!=true)   // writting first tweet in file for user
                {
                    out<<id<<"\n"<<"T: "<<tweet_num<<":"<<Text<<"\n"<<0<<"\n"<<Line<<"\n"<<star<<"\n";
                }
                out.close();
                ofstream out1("Tweets.txt"); ifstream in1("temp.txt");
                if(out1.is_open()==true && in1.is_open()==true)
                {
                    while(getline(in1 , text))
                    {
                        out1<<text<<"\n";
                    }
                    in1.close() ; out1.close();
                    flag="*successfully done.";
                }
            }
        }
        if (flag=="*successfully done.") // add tweet to likes file
        {
            if(add_to_likes(id , tweet_num)!=true) flag="!File cant open.";
        }
    }
    else flag="!User not found.";

    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: add_mention (string &Username , string &user_mention , string &Text , string &tweet_number)
{
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    if(user_mention[0]=='@') user_mention=user_mention.substr(1); user_mention=ToLower(user_mention);
    string id=get_id(Username) , id_mention=get_id(user_mention) ;   bool flag1=false;
    string star="*****************************" , Line="------------------------------";
    string flag="file cant open." , uname , text="null" , like="null" ; int number=0 , number1=1;
    if(id!="no user found." && id!="not found." && id_mention!="no user found." && id_mention!="not found.")
    {
        ifstream in("Tweets.txt");
        if(!in) flag="!No tweets found.";
        else
        {
            int Tweet_number=To_int(tweet_number);
            ofstream out("temp.txt");
            if(out.is_open()==true)
            {
                while(getline(in , uname))
                {
                    out<<uname<<"\n";
                    while(text!=star)
                    {
                        getline(in, text) ; out<<text<<"\n";
                        if(text!=star && text!=Line)
                        {
                            getline(in , like ) ; out<<like<<"\n";
                        }
                        if(uname==id && text.size() > 3){
                            if(text.substr(0 , 3)=="T: ") //finding tweet
                            {
                                number++;
                                if(Tweet_number==number){
                                    getline(in , text);
                                    while(text!=Line)   // add mention
                                    {
                                        getline(in , like); out<<text<<"\n"<<like<<"\n"; number1++; //numbe1->mention number
                                        getline(in , text);
                                    }
                                    flag1=true;
                                    out<<"M: "<<id_mention<<":"<<number1<<"_"<<Text<<"\n"<<0<<"\n"<<Line<<"\n";
                                }
                            }
                        }
                    }
                    text="null";
                }
                in.close() ; out.close();
                ofstream out1("Tweets.txt"); ifstream in1("temp.txt");
                if(out1.is_open()==true && in1.is_open()==true) {
                    while(getline(in1 ,text)){out1<<text<<"\n";} //copy
                    in1.close() ; out1.close();
                    if(flag1==true)
                    {                       // add mention to likes_mention file
                        if(add_to_like_mention(id , tweet_number , number1)==true)
                            flag="*successfully done.";
                    }
                    else flag="!Tweet not found.";
                }
            }
        }
    }
    else flag="!User not found.";

    return flag;
}

/////////////////////////////////////////////////////////////////////////

bool User:: add_to_likes(string &id1 , int number)
{
    string star="*****************************" , Id , text="null" ;
    string Line="------------------------------";
    bool flag=false , flag1=false;
    ifstream in("likes.txt");
    if(!in)
    {
        ofstream out("likes.txt");
        if(out.is_open()==true)
        {
            out<<id1<<"\n"<<number<<"\n"<<Line<<"\n"<<star<<"\n";
            out.close(); flag=true;
        }
    }
    else
    {
        ofstream out("temp.txt");
        if(out.is_open()==true)
        {
            while(in>>Id)
            {
                out<<Id<<"\n";
                while(text!=star)
                {
                    in>>text;
                    if(Id==id1 && text==star)
                    {
                        out<<number<<"\n"<<Line<<"\n"; flag1=true;
                    }
                    out<<text<<"\n";
                }
                text="null";
            }
            in.close();
            if(flag1!=true)  out<<id1<<"\n"<<number<<"\n"<<Line<<"\n"<<star<<"\n";
            out.close() ;
            ofstream out1("likes.txt"); ifstream in1("temp.txt");
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while(in1>>text) out1<<text<<"\n";
                in1.close() ; out1.close(); flag=true;
            }
        }
    }
    return flag;
}

/////////////////////////////////////////////////////////////////////////

string User:: Show_tweet(string &Username)
{
    if(Username[0]=='@') Username=Username.substr(1);
    Username=ToLower(Username);
    string star="*****************************",Line="------------------------------";
    stringstream aa ; bool flag=false;
    string id=get_id(Username) , uname , text="null" , like;
    ifstream in("Tweets.txt");
    if(!in || id=="no user found." || id=="not found." )
    {
        aa<<"!No tweet found.";
    }
    else
    {
        if(id[0]=='A') aa<<"!This option is not available for this account. ";
        else
        {
            while(getline(in , uname))
            {
                while(text!=star)
                {
                    getline(in ,text);
                    if(text!=star && text!=Line) getline(in , like);
                    if(uname==id)
                    {
                        flag=true;
                        if(text.size() > 3 && text!=star && text!=Line)
                        {
                            string temp=text.substr(3) , temp1;  //sprate tweet or mention from T: or M:
                            if(text.substr( 0 , 3)=="T: ") aa<<temp<<"\n"; // writting tweet
                            else if (text.substr( 0 , 3)=="M: ")
                            {
                                stringstream  a(temp);
                                getline(a , temp1 , ':');  // sprate id from mention
                                temp=temp.substr(temp1.size());
                                temp1=get_username_id(temp1);
                                if(temp1!="no user found." && temp1!="not found.")
                                {
                                    aa<<"Mention: "<<"@"<<temp1<<temp<<"\n";
                                }
                                else aa<<"Mention: "<<"@delete_accounted:"<<temp<<"\n";
                            }
                            if(text!=star && text!=Line) aa<<"likes:"<<like<<"\n"<<star<<"\n";
                        }
                    }
                }
                if(flag==true) break;
                text="null";
            }
            in.close();
        }
    }
    return aa.str();
}

/////////////////////////////////////////////////////////////////////////

bool User:: Hashtag(string &hashtag1)
{
    int size=hashtag1.size() , counter=0; // validation hashtag
    bool flag=false;
    for (int i=0 ; i < size ; i++ )
    {
        if(hashtag1[i]==' ') counter++;
    }
    if (counter==0 && hashtag1[0]=='#' && size > 1) flag=true;
    cout<<hashtag1[0]<<hashtag1;
    return flag;
}

/////////////////////////////////////////////////////////////////////////

bool User:: check_hashtag(string &text , string &hashtag)
{
    bool flag=false;  string temp;
    int find=text.find("#");
    if(find > -1 && find < text.size())
    {
        vector <string> a;
        stringstream aa(text);
        while (aa.good())
        {
            getline(aa , temp , '#'); a.push_back(temp);
        }
        int size=a.size();
        for(int i=1 ; i<size ; i++)
        {
            a[i]=sprator(a[i]);
            a[i]=ToLower(a[i]);
            if(a[i]==hashtag)
            {
                flag=true;
            }
        }

    }
    return flag;
}

/////////////////////////////////////////////////////////////////////////
string User:: sprator(string &input)
{
    string temp;
    stringstream aa(input);
    getline(aa , temp , ' ');
    return temp;
}
/////////////////////////////////////////////////////////////////////////

string User:: hashtag_search(string &hashtag)
{
    stringstream aa; bool flag=false;
    string star="*****************************" ,Line="------------------------------";
    string uname , text="null" , like;
    cout<<Hashtag(hashtag);
    if(Hashtag(hashtag)==true)
    {
        hashtag=hashtag.substr(1); hashtag=ToLower(hashtag);
        ifstream in("Tweets.txt");
        if(!in) aa<<"!No tweet found.";
        else
        {
            while(getline(in , uname))
            {
                while (text!=star)
                {
                    getline(in , text);
                    if(text!=star && text!=Line) getline(in , like);
                    if(text!=star && text!=Line && check_hashtag(text , hashtag)==true)
                    {
                        flag=true;
                        string temp=text.substr(3) , temp1; //sprate tweet or mention from T: or M:
                        if(text.substr( 0 , 3)=="T: ")
                        {
                            temp1=get_username_id(uname);
                            if(temp1!="no user found." && temp1!="not found.")
                            {
                                aa<<"@"<<temp1<<":"<<temp<<"\n"<<"likes:"<<like<<"\n"<<star<<"\n";
                            }
                              else aa<<"!Not found";
                        }
                        else if (text.substr( 0 , 3)=="M: ")
                        {
                            stringstream  a(temp);
                            getline(a , temp1 , ':'); //sprate id from mention
                            temp=temp.substr(temp1.size());
                            temp1=get_username_id(temp1);
                            if(temp1!="no user found." && temp1!="not found.")
                            {
                                aa<<"Mention: "<<"@"<<temp1<<temp<<"\n"<<"likes:"<<like<<"\n"<<star<<"\n";
                            }
                            else aa<<"!Not found";
                        }
                    }
                }
                text="null";
            }
            in.close();
            if(flag!=true) aa<<"!Not found.";
        }
    }
    else
    {
        cout<<"hh";
        aa<<"!hashtag is not true.";
    }
    //cout<<flag;
    return aa.str();
}

/////////////////////////////////////////////////////////////////////////

bool User:: delete_account(string &Username)
{
    bool flag=false;
    if(Username[0]=='@') Username=Username.substr(1);
    Username=ToLower(Username);
    ifstream in("id.txt") ; ofstream out("temp.txt");
    if(in.is_open()==true && out.is_open()==true)
    {
        string uname , id;
        while(in>>uname>>id)
        {
            if(uname!=Username)
            {
                out<<uname<<"\t"<<id<<"\n";
            }
        }
        in.close() ; out.close() ;
        ifstream in1("temp.txt") ; ofstream out1("id.txt");
        if(in1.is_open()==true && out1.is_open()==true)
        {
            while(in1>>uname>>id)
            {
                out1<<uname<<"\t"<<id<<"\n";
            }
            flag=true;  in1.close() ; out1.close() ;
        }
    }
}

/////////////////////////////////////////////////////////////////////////

string  User:: get_profile (string &Username , string &Color)
{
    stringstream aa; bool flag=false; string uname , text ; int counter;
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    string id=get_id(Username) , star="*****************************";
    if( id!="no user found." && id!="not found.")
    {
        if(id[0]=='A')
        {
            aa<<"***** Anonymous User *****"<<"\n";
            aa<<"Username:@"<<Username<<"\n"<<star<<"\n";
            aa<<"Name:Anonymous User"<<"\n"<<star<<"\n";
        }
        else
        {
            ifstream in("profiles.txt");
            if(in.is_open()==true)
            {
                while(getline( in , uname))
                {
                    if(uname==id)
                    {
                        flag=true;
                        aa<<"Username:@"<<Username<<"\n"<<star<<"\n";
                        getline(in , text);
                        if(uname[0]=='O') aa<<"Username the boss of organization:@"<<text<<"\n"<<star<<"\n";
                        else aa<<"Username of organization:@"<<text<<"\n"<<star<<"\n";
                        getline(in , text); aa<<"Name:"<<text<<"\n"<<star<<"\n";
                        getline(in , text); aa<<"Biography:"<<text<<"\n"<<star<<"\n";
                        getline(in , text); aa<<"Phonenumber:"<<text<<"\n"<<star<<"\n";
                        getline(in , text); aa<<"Country:"<<text<<"\n"<<star<<"\n";
                        getline(in , text); aa<<"Link:"<<text<<"\n"<<star<<"\n";
                        getline(in , text); Color=text;
                        if(uname[0]=='P')
                        {
                            getline(in , text);  aa<<"Birthdaydate:"<<text<<"\n"<<star<<"\n";
                        }
                        getline(in , text);

                    }
                    else
                    {
                        if(uname[0]=='O') counter=8;  if(uname[0]=='P') counter=9; //organition or personal type
                        for(int i=0 ; i< counter ; i++)  getline(in , text);
                    }
                    if(flag==true) break;
                }
                in.close();
            }
            else aa<<"!File cant open.";
        }
    }
    else aa<<"!User not found.";

    return aa.str();
}

/////////////////////////////////////////////////////////////////////////

bool User:: add_to_follow(string &id)
{
    bool flag=false; string star="*****************************" ;
    string Line="------------------------------";
    ofstream out("following_followers.txt" , ios::app);
    {
        if(out.is_open()==true)  // add user to following_follower file
        {
            out<<id<<"\n"<<"following"<<"\n"<<"0"<<"\n"<<Line<<"\n";
            out<<"followers"<<"\n"<<"0"<<"\n"<<Line<<"\n"<<star<<"\n";
            out.close(); flag=true;
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: follow_unfollow(string &Username , string &Username_for_follow) //In this function, it is checked whether the user already follows the intended user or not
{
    string star="*****************************",Line="------------------------------";
    string flag , id , id_for_follow , uname , text="null"  ; int follower , following;
    if(Username[0]=='@') Username=Username.substr(1); bool flag1=false , flag2=false;
    if(Username_for_follow[0]=='@') Username_for_follow=Username_for_follow.substr(1);
    Username=ToLower(Username);  Username_for_follow=ToLower(Username_for_follow);
    id=get_id(Username) ; id_for_follow=get_id(Username_for_follow);
    if(id!=id_for_follow)
    {
        if(id!="no user found." && id!="not found." &&  id_for_follow!="no user found." && id_for_follow!="not found.")
        {
            if(id_for_follow[0]!='A')
            {
                ifstream in("following_followers.txt");
                if(in.is_open()==true)
                {
                    vector <string> followers; vector <string> followings;
                    while(in>>uname)
                    {
                        while(text!=star)
                        {
                            in>>text;
                            if(uname==id && text=="following")
                            {
                                in>>following; flag1=true;
                                while(text!=Line)
                                {
                                    followings.push_back(text); in>>text;
                                }
                            }
                            else if(uname==id_for_follow && text=="followers")
                            {
                                in>>follower; flag2=true;
                                while(text!=Line)
                                {
                                    followers.push_back(text); in>>text;
                                }
                            }
                        }
                        if(flag1==true && flag2==true) break;
                        else text="null";
                    }
                    in.close(); flag1=true; flag2=true ; int size1=followers.size() , size2=followings.size();
                    for(int i=0 ; i<size1 ; i++)                                                                        //if followed->unfollow
                    {
                        if(followers[i]==id){flag1=false; followers.erase(followers.begin()+i) ; follower--;}
                    }
                    for(int i=0 ; i<size2 ; i++)
                    {
                        if(followings[i]==id_for_follow){flag2=false; followings.erase(followings.begin()+i) ; following--;}
                    }
                    if(flag1==true) {followers.push_back(id) ; follower++;}
                    if(flag2==true) {followings.push_back(id_for_follow) ; following++;}                                //if did not follow->follow
                    stringstream x , y;
                    x<<followings[0]<<"\n"<<following<<"\n"; y<<followers[0]<<"\n"<<follower<<"\n";
                    for(auto &i : followings) { if(i!="following") x<<i<<"\n";}
                    for(auto &i : followers)  {if(i!="followers") y<<i<<"\n";}
                    string temp=x.str() , temp1=y.str();
                    flag=add_to_file(id , id_for_follow , temp , temp1 , flag1);
                }
            }
            else flag="!You cant follow this account.";
        }
        else flag="!User not found.";
    }
    else {
        flag="! You can not Follow yourself.";
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: add_to_file(string &Id , string &Id_for_follow ,string &Followings , string &Followers,bool flag1)
{
    string star="*****************************",Line="------------------------------";
    string flag , uname , text="null";
    ifstream  in("following_followers.txt"); ofstream out("temp.txt");
    if(in.is_open()==true && out.is_open()==true)
    {
        while(in>>uname)
        {
            out<<uname<<"\n";
            while(text!=star)
            {
                in>>text;
                if(uname==Id && text=="following")
                {
                    out<<Followings<<Line<<"\n";
                    while(text!=Line){ in>>text; }
                }
                else if(uname==Id_for_follow && text=="followers")
                {
                    out<<Followers<<Line<<"\n";
                    while(text!=Line) {in>>text;}
                }
                else out<<text<<"\n";
            }
            text="null";
        }
        in.close() ; out.close();
        ifstream in1("temp.txt") ; ofstream out1("following_followers.txt") ;
        if(in1.is_open()==true && out1.is_open()==true)
        {
            while(in1>>text) {out1<<text<<"\n";}
            in1.close() ; out1.close();
            if(flag1==true) flag="*Successfully followed.";
            else flag="*Successfully unfollowed.";
        }
    }
    else flag="!User not found.";
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: get_following_or_followers (string &Username , string &number , string type)
{
    string star="*****************************",Line="------------------------------";
    string  id ,  uname , text="null"  ; bool flag=false ;
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    id=get_id(Username) ; stringstream aa;
    if(type=="following" || type=="followers")
    {
        if(id!="no user found." && id!="not found.")
        {
            ifstream in("following_followers.txt");
            if(in.is_open()==true)
            {
                while(in>>uname)
                {
                    while(text!=star)
                    {
                        in>>text;
                        if(uname==id && text==type)
                        {
                            in>>number;  flag=true;
                            while(text!=Line)
                            {
                                in>>text;
                                string temp=get_username_id(text);
                                if(temp!="no user found." && temp!="not found.")aa<<"@"<<temp<<"\n";
                            }
                        }
                    }
                    if(flag==true) break;
                    else text="null";
                }
                in.close();
            }
            flag="!File cant open.";
        }
        else aa<<"!User not found.";
    }
    else aa<<"!Invaliv type";
    return aa.str();
}

//////////////////////////////////////////////////////////////////////////

string User::  add_like_tweet(string &Username , string &User_like , string &tweet_num)//In this function, it is checked whether the user has already liked the desired user or not
{
    string star="*****************************",Line="------------------------------";
    string  flag="!File cant open." ,  uname , text="null" , type="like"  ; bool flag1=false ;
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    if(User_like[0]=='@') User_like=User_like.substr(1); User_like=ToLower(User_like);
    string id=get_id(Username) , id_like=get_id(User_like) ;
    if(id!="no user found." && id!="not found.", id_like!="no user found." && id_like!="not found.")
    {
        if(To_int(tweet_num)!=0)
        {
            ifstream in("likes.txt") ; ofstream out("temp.txt");
            if(in.is_open()==true && out.is_open()==true)
            {
                while(in>>uname)
                {
                    out<<uname<<"\n";
                    while(text!=star)
                    {
                        in>>text;
                        if(uname==id && text==tweet_num)
                        {
                            out<<text<<"\n";
                            flag1=true;
                            in>>text;
                            while(text!=Line)
                            {
                                if(text==id_like) type="dislike"; // If user liked it-> dislike
                                else  out<<text<<"\n";
                                in>>text;
                            }
                            if(type=="like") out<<id_like<<"\n";
                        }
                        out<<text<<"\n";
                    }
                    text="null";
                }
                in.close(); out.close();
                if(flag1!=true) flag="!Tweet not found";
                else                                        //if did not like->like;
                {
                    ifstream in1("temp.txt") ; ofstream out1("likes.txt") ;
                    if(in1.is_open()==true && out1.is_open()==true)
                    {
                        while(in1>>text){out1<<text<<"\n"; }
                        in1.close(); out1.close();
                        int tweet_number=To_int(tweet_num);
                        if(likes_dislikes(id , tweet_number , type)==true)
                        {
                            if(type=="like") flag="*successfully liked.";
                            else flag="*successfully dilsliked.";
                        }
                    }
                }
            }
        }
        else flag="!Invalid tweet number.";
    }
    else flag="!User not found.";
    return flag;
}

//////////////////////////////////////////////////////////////////////////

bool User:: likes_dislikes(string &id1 ,int &tweet_number , string like_or_dislike)
{
    bool flag=false;
    string uname , text="null" , like ; int  number=0 ;
    string star="*****************************" , Line="------------------------------";
    ifstream in("Tweets.txt") ; ofstream out("temp.txt");
    if(in.is_open()==true && out.is_open()==true)
    {
        while(getline(in , uname))
        {
            out<<uname<<"\n";
            while(text!=star)
            {
                getline(in , text);
                if(text!=star && text!=Line) getline(in , like);
                if(uname==id1 && text.size() > 3)
                {
                    if(text.substr(0 , 3)=="T: ")
                    {
                        number++;
                        if(tweet_number==number)
                        {
                            int likes=To_int(like);
                            if(like_or_dislike=="like") likes++;
                            else likes--;
                            stringstream aa; aa<<likes ; like=aa.str();
                        }
                    }
                }
                out<<text<<"\n";
                if(text!=star && text!=Line) out<<like<<"\n";
            }
            text="null";
        }
        in.close() ; out.close();
        ifstream in1("temp.txt"); ofstream out1("Tweets.txt");
        if(in1.is_open()==true && out1.is_open()==true)
        {
            while(getline(in1 , text)) out1<<text<<"\n";
            in1.close() ; out1.close();
            flag=true;
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

bool User:: add_to_like_mention(string &Id ,  string &tweet_number1 , int &mention_num)//In this function, it is checked whether the user has already liked the desired user or not
{
    bool flag=false, flag1=false; string uname , text="null";
    string star="*****************************",Line="------------------------------";
    ifstream in("likes_mention.txt") ;
    if(!in)
    {
        ofstream out("likes_mention.txt");
        if(out.is_open()==true)
        {
            flag=true;
            out<<Id<<"\n"<<tweet_number1<<":"<<mention_num<<"\n"<<Line<<"\n"<<star<<"\n";
        }
    }
    else
    {
        ofstream out("temp.txt");
        if(out.is_open()==true)
        {
            while (in>>uname)
            {
                out<<uname<<"\n";
                while(text!=star)
                {
                    in>>text;
                    if(uname==Id && text==star)
                    {
                        flag1=true;
                        out<<tweet_number1<<":"<<mention_num<<"\n"<<Line<<"\n";
                    }
                    out<<text<<"\n";
                }
                text="null";
            }
            in.close();
            if(flag1!=true) out<<Id<<"\n"<<tweet_number1<<":"<<mention_num<<"\n"<<Line<<"\n"<<star<<"\n";
            out.close();
            ifstream in1("temp.txt") ; ofstream out1("likes_mention.txt") ;
            if(in1.is_open()==true && out1.is_open()==true)
            {
                while(in1>>text)
                {
                    out1<<text<<"\n";
                }
                in1.close(); out1.close();
                flag=true;
            }
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: add_like_mention(string &Username , string &User_like ,string &mention_num , string &tweet_num)
{
    string flag="!File cant open",uname ,temp, text="null", type="like" , Line="------------------------------";
    string star="*****************************"; bool flag1=false;
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    if(User_like[0]=='@') User_like=User_like.substr(1); User_like=ToLower(User_like);
    string id=get_id(Username) , id_like=get_id(User_like); vector <string> temp1;
    if(id!="no user found." && id!="not found.", id_like!="no user found." && id_like!="not found.")
    {
        ifstream in("likes_mention.txt") ;  ofstream out("temp.txt");
        if(in.is_open()==true && out.is_open()==true)
        {
            while(in>>uname)
            {
                out<<uname<<"\n";
                while(text!=star)
                {
                    in>>text;
                    stringstream aa(text);
                    if(flag1!=true && uname==id && text!=Line)
                    {
                        for(int i=0 ; i<2 ; i++)
                        {
                            getline(aa , temp , ':') ; temp1.push_back(temp);
                        }
                        if(temp1[0]==tweet_num && temp1[1]==mention_num)
                        {
                            out<<text<<"\n";
                            in>>text;  flag1=true;
                            while(text!=Line)
                            {
                                if(text==id_like) type="dislike";
                                else{out<<text<<"\n";}
                                in>>text;
                            }
                            if(type=="like") out<<id_like<<"\n";
                        }
                        temp1.clear(); aa.clear();
                    }
                    out<<text<<"\n";
                }
                text="null";
            }
            in.close(); out.close();
            if(flag1!=true) flag="!Mention not found";
            else
            {
                ifstream in1("temp.txt") ; ofstream out1("likes_mention.txt") ;
                if(in1.is_open()==true && out1.is_open()==true)
                {
                    while(in1>>text) {out1<<text<<"\n";}
                    in1.close(); out1.close();

                    if(like_dislike_mention(id , type , tweet_num , mention_num)==true)
                    {
                        if(type=="like") flag="!successfully liked.";
                        else flag="*successfully disliked.";
                    }
                }
            }
        }
        else flag="!No tweet found.";
    }
    else flag="!User not found.";
    return flag;
}

//////////////////////////////////////////////////////////////////////////

bool User:: like_dislike_mention(const string &Id ,const string &type1 , string &tweet_num1 , string &mention_num1)
{
    string uname , text="null", like , Line="------------------------------" ,star="*****************************";
    bool flag=false;
    int num1=0 , num2=0 , tweet_number=To_int(tweet_num1) , mention_number=To_int(mention_num1) , likes;
    ifstream in("Tweets.txt") ; ofstream out("temp.txt") ;
    if(in.is_open()==true && out.is_open()==true)
    {
        while(getline(in , uname))
        {
            out<<uname<<"\n";
            while(text!=star)
            {
                getline(in , text);
                if(text!=star && text!=Line) getline(in , like) ;
                if(uname==Id && text.size() > 3 && text!=star)
                {
                    if(text.substr(0 , 3)=="T: ")
                    {
                        num1++;
                        if(num1==tweet_number)
                        {
                            out<<text<<"\n"<<like<<"\n";
                            getline(in , text);
                            while(text!=Line)
                            {
                                getline(in , like) ; num2++;
                                if(num2==mention_number)
                                {
                                    likes=To_int(like);
                                    if(type1=="like") likes++;
                                    else likes--; out<<text<<"\n"<<likes<<"\n";
                                }
                                else out<<text<<"\n"<<like<<"\n";
                                getline(in , text);
                            }
                        }
                    }
                }
                out<<text<<"\n";
                if(text!=star && text!=Line) out<<like<<"\n";
            }
            text="null";
        }
        out.close() ; in.close();
        ofstream out1("Tweets.txt"); ifstream in1("temp.txt");
        if(out1.is_open()==true && in1.is_open()==true)
        {
            while(getline(in1 ,text)) {out1<<text<<"\n";}
            in1.close() ; out1.close();
            flag=true;
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User::retweet_or_qotetweet(string &Username,string &User_retweet,const string &tweet_num,string Text)
{
    string flag ,uname ,temp, text="null", like , Line="------------------------------";
    string star="*****************************"; bool flag1=false; int num=0 , tweet_number=To_int(tweet_num);
    if(Username[0]=='@') Username=Username.substr(1); Username=ToLower(Username);
    string id=get_id(Username);
    if(id!="no user found." && id!="not found.")
    {
        ifstream in("Tweets.txt");
        if(!in)
        {
            flag="!No tweet found";
        }
        else
        {
            while(getline(in , uname))
            {
                while(text!=star)
                {
                    getline(in , text);
                    if(text!=star && text!=Line) getline(in , like);
                    if(uname==id && text.size()>3 )
                    {
                        if(text.substr( 0 , 3)=="T: ")
                        {
                            num++;
                            if(num==tweet_number)
                            {
                                stringstream aa;
                                if(Text!="null") aa<<Text<<"\t";
                                aa<<"@"<<Username<<":"<<text.substr(3);
                                flag1=true; temp=aa.str();
                            }
                        }
                    }
                }
                if(flag1==true) break;
                else text="null";
            }
            in.close();
        }
        if(flag1!=true) flag="!Tweet not found.";
        else flag=add_tweet(User_retweet , temp );

    }
    else flag="!User not found";
    return flag;
}

//////////////////////////////////////////////////////////////////////////

string User:: get_profilepic(){

    return address;
}
/////////////////////////////////////////////////////////////////////////////

void User:: set_profile(string &add){
    address=add;
}
/////////////////////////////////////////////////////////////////////////////

string User:: get_profilepic_file(string uname){
    if(uname[0]=='@') uname=uname.substr(1) ; uname=ToLower(uname);
    string id=get_id((uname)),ID,ads="nl";
    ifstream in("profile_pic.txt");
    if(in.is_open()==true)
    {
        char line[2000];
        while(in.getline(line , 2000))
        {
            ID=line;
            if(ID==id)
            {
                in.getline(line , 2000);
                ads=line;
                address=line;
                break;
            }
            in.getline(line , 2000) ;
            in.getline(line , 2000) ;
        }
        in.close();
    }
    else{

        ads="! file can not open";
    }
    return ads;
}

/////////////////////////////////////////////////////////////////////////////

string User:: edit_profile(string &uname,string &prof){

    string flag="!file cant open." ,ID , text ; // counters are for reading and writting correctly
    if(uname[0]=='@') uname=uname.substr(1) ; uname=ToLower(uname);
    string id=get_id(uname);
    if(id!="no user found." && id!="not found." && id[0]!='A')
    {

        if(get_profilepic()==""||get_profilepic()=="null"){
            ofstream out3("profile_pic.txt");
            if(out3.is_open()==true)
            {
                string star="*****************************";
                out3<<id<<endl<<prof<<endl<<star<<endl;
                out3.close();
            }
        }
            set_profile(prof);
            ifstream in("profile_pic.txt") ; ofstream out("temp.txt");
            while(getline(in , ID))
            {
                out<<ID<<"\n";
                if(ID==id)
                {
                if(prof==""){

                    prof="C:/Users/Yasaman/Desktop/profiles/withoutprofile.jpg";
                }
                   // getline(in , text); out<<text<<"\n";
                    getline(in , text); out<<prof<<"\n";

                }
                else
                {
                     getline(in , text); out<<text<<"\n";

                }
            }
            in.close() ; out.close() ;
            ifstream in1("temp.txt") ; ofstream out1("profile_pic.txt");
            if(out1.is_open()==true && in1.is_open()==true)
            {
                while(getline(in1 , text)) //copy
                {
                    out1<<text<<"\n";
                }
                in1.close() ; out1.close();
                flag="*successfully done.";
            }
    }
    else if(id[0]=='A'){
            flag="! this option is not avalable for you.";
    }
    else flag="!User not found.";

    return flag;
}




