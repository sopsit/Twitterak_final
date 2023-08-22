#include "app.h"
#include "ui_app.h"
#include "tweet.h"
#include "own_tweet.h"
#include "user.h"
#include "searchs.h"
#include "profile.h"
#include"otherstweets.h"
#include"myprofile.h"
#include"showuthprof.h"
#include <QMessageBox>
#include<iostream>
#include<qdebug.h>
#include<QPixmap>
using namespace std;
app::app(User*& logins,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::app)
   // users(logins)
{
    ui->setupUi(this);
    users=logins;
    QPixmap *img = new QPixmap("C:/Users/Yasaman/Desktop/logos/logo2.png");
    ui->label->setPixmap(*img);

}


app::~app()
{
    delete ui;
}
void app::print(){
    string uname=users->get_username();
    QMessageBox msgBox;
    msgBox.setText(QString ::fromStdString( uname));
    msgBox.exec();
}
void app::on_pushButton_clicked()
{
    QString CurrentVal;
    CurrentVal = ui->comboBox->currentText();
    string CurrentVall=CurrentVal.toStdString();

    if(CurrentVall=="new Tweet"){

        tweet *page=new tweet(users);
        page->show();
    }
    else if(CurrentVall=="Show my Tweets"){
        own_tweet *page=new own_tweet(users);
        page->show();
    }
    else if(CurrentVall=="Show others tweets"){
        othersTweets *page=new othersTweets(users);
        page->show();
    }
    else if(CurrentVall=="Edit profile"){
        profile *page=new profile(users);
        page->show();
    }
    else if(CurrentVall=="Search for '#'"){
        searchs *page=new searchs(users);
        page->show();
    }
    else if(CurrentVall=="Delete account"){
        delete users;
        string  uname=users->get_username();
        users->delete_account(uname);
        QMessageBox msgBox;
        msgBox.setText("! Deleted");
        msgBox.exec();
        exit(0);
    }
    else if(CurrentVall=="My profile"){
        MyProfile *page= new MyProfile(users);
        page->show();
    }
    else if(CurrentVall=="Logout"){
        delete users;
        QMessageBox msgBox;
        msgBox.setText("Logouted successfuly");
        msgBox.exec();
        exit(0);
    }
    else if(CurrentVall=="Show others profile"){
        showuthprof *page=new showuthprof(users);
        page->show();
    }

}



