#include "tweet.h"
#include "ui_tweet.h"
#include"user.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
tweet::tweet(User*& users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tweet)
{
    ui->setupUi(this);
    //cout<<users->get_username();
    usert=users;
}

tweet::~tweet()
{
    delete ui;
}

void tweet::on_pushButton_clicked()
{
    QString tweets=ui->lineEdit->text();
    string uname=usert->get_username(),tweet,res;
    tweet=tweets.toStdString();
    int counter=0;
    for(int i=0; i<tweet.size(); i++){
        if(tweet[i]==' ')
            counter++;
    }
    if(tweet==""||counter==tweet.size()){
        res="! invalid tweet.";
        QMessageBox msgBox1;
        msgBox1.setText(QString::fromStdString(res));
        msgBox1.exec();
    }
    else{
    res=usert->add_tweet(uname, tweet);
    QMessageBox msgBox1;
    msgBox1.setText(QString::fromStdString(res));
    msgBox1.exec();

    }
    this->close();
}

