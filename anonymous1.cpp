#include "anonymous1.h"
#include "ui_anonymous1.h"
#include "anonymous.h"
#include "app.h"
//#include "signup.h"
#include "user.h"
#include "QMessageBox"
//#include"signup.h"
#include"anonymous.h"

#include <iostream>
using namespace std;
anonymous1::anonymous1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anonymous1)
{
    ui->setupUi(this);
}

anonymous1::~anonymous1()
{
    delete ui;
}

void anonymous1::on_pushButton_clicked()
{
    QString uname, pass;
    uname= ui->lineEdit->text();
    pass= ui->lineEdit_2->text();
    string uname1, pass1,res;
    uname1=uname.toStdString();
    pass1=pass.toStdString();

    Anonymous temp;
    res=temp.signup(uname1,pass1);

    if(res=="! You have successfully signed up.")
    {
        anonymouses= new Anonymous;
        anonymouses->set_username(uname1);
        anonymouses->set_password(pass1);
        app *page=new app(anonymouses);
        page->show();
    }
    else{
        QMessageBox MyMSG;
        MyMSG.setText(QString::fromStdString(res));
        MyMSG.exec();
    }




}

