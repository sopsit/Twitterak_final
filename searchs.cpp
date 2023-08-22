#include "searchs.h"
#include "ui_searchs.h"
#include"user.h"
searchs::searchs(User *&users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchs)
{
    ui->setupUi(this);
    userse=users;
}

searchs::~searchs()
{
    delete ui;
}

void searchs::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString txt=ui->lineEdit->text();
    string text=txt.toStdString();
        string res;
        res=userse->hashtag_search(text);
        ui->listWidget->addItem(QString::fromStdString(res));

}

