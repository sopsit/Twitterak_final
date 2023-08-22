#include "own_tweet.h"
#include "ui_own_tweet.h"
#include "user.h"
#include <QListWidget>
own_tweet::own_tweet(User *&users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::own_tweet)
{
    ui->setupUi(this);
    usertm=users;
    string res,uname;
    uname=usertm->get_username();
    res=usertm->Show_tweet(uname);
    ui->listWidget->addItem(QString::fromStdString(res));


}

own_tweet::~own_tweet()
{
    delete ui;
}

void own_tweet::on_pushButton_clicked()
{
    this->close();
}

