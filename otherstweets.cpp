#include "otherstweets.h"
#include "ui_otherstweets.h"
#include"user.h"
#include <QListWidget>
#include <QMessageBox>
othersTweets::othersTweets(User*& users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::othersTweets)
{
    ui->setupUi(this);
    othTweets=users;
}

othersTweets::~othersTweets()
{
    delete ui;
}


void othersTweets::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString uname=ui->lineEdit->text();
    username=uname.toStdString();
    string tweets=othTweets->Show_tweet(username);
    ui->listWidget->addItem(QString::fromStdString(tweets));

}

void othersTweets::on_pushButton_4_clicked()
{
    this->close();
}

void othersTweets::on_add_mention_clicked()
{
    QString number=ui->tweetsnum->text(), text=ui->mention->text();
    string own_uname=othTweets->get_username(),number1=number.toStdString(),text1=text.toStdString(),res;
    res=othTweets->add_mention(username,own_uname,text1,number1);
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(res));
    msgBox.exec();
    string tweets=othTweets->Show_tweet(username);
    ui->listWidget->addItem(QString::fromStdString(tweets));
    on_pushButton_clicked();
}


void othersTweets::on_like_tweet_clicked()
{
    QString number=ui->like->text();
    string own_uname=othTweets->get_username(), num=number.toStdString(), res;
    res=othTweets->add_like_tweet(username, own_uname, num);
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(res));
    msgBox.exec();
    on_pushButton_clicked();
}



void othersTweets::on_add_mention_2_clicked()
{
    QString number=ui->tweetsnum_4->text(),number1=ui->tweetsnum_3->text();
    string own_uname=othTweets->get_username(), num1=number.toStdString(),num2=number1.toStdString(), res;
    res=othTweets->add_like_mention(username,own_uname,num1,num2);
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(res));
    msgBox.exec();
    on_pushButton_clicked();
}


void othersTweets::on_retweet_clicked()
{
    QString number=ui->like_retweet->text();
    string own_uname=othTweets->get_username(), num1=number.toStdString(), res;
    res=othTweets->retweet_or_qotetweet(username,own_uname,num1,"null");
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(res));
    msgBox.exec();
    on_pushButton_clicked();
}


void othersTweets::on_qoute_clicked()
{
    QString number=ui->tweetsnum_2->text(),txt=ui->qoute_txt->text();
    string own_uname=othTweets->get_username(), num1=number.toStdString(), res,txt1=txt.toStdString();
    res=othTweets->retweet_or_qotetweet(username,own_uname,num1,txt1);
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(res));
    msgBox.exec();
    on_pushButton_clicked();
}

