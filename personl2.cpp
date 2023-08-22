#include "personl2.h"
#include "ui_personl2.h"
#include<iostream>
#include "personal.h"
#include "app.h"
#include "user.h"
#include<QFileDialog>
#include <QMessageBox>
using namespace std;
personl2::personl2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personl2)
{
    ui->setupUi(this);
   // personals=signups;
}

personl2::~personl2()
{
    delete ui;
}

void personl2::on_pushButton_clicked()
{
    QString a,a2,a3,a4,a5,a6,a7,a10,a9,a11,res2;
    string b,b1,b2,b3,b4,b5,b6,b7,b8,b9,b11,res;
    a=ui->lineEdit->text();//username
    a2=ui->lineEdit_2->text();//birthday
    a4=ui->lineEdit_4->text();//country
    a5=ui->lineEdit_5->text();//color
    a6=ui->lineEdit_6->text();//phone
    a7=ui->lineEdit_7->text();//bio
    a3=ui->lineEdit_3->text();//org
    a9=ui->lineEdit_9->text();//name
    a10=ui->lineEdit_10->text();//link
    a11=ui->lineEdit_11->text();//pass
    b=a.toStdString();
    b2=a2.toStdString();
    b3= a3.toStdString();
    b4=a4.toStdString();
    b5=a5.toStdString();
    b6=a6.toStdString();
    b7=a7.toStdString();
    b8=a10.toStdString();
    b9=a9.toStdString();
    b11=a11.toStdString();
    personal temp;
    res=temp.signup(b,b11,b9,b6,b7,b4, b8,b5 ,b3 ,b2,prof);
    if(res=="! You have successfully signed up."){
        personals= new personal;
        personals->set_username(b);
        personals->set_password(b11);
        //personals=&temp;
        //personals->set_profile(prof);
        app *page=new app(personals);
        page->show();
    }
    else{
        QMessageBox MyMSG;
        MyMSG.setText(QString::fromStdString(res));
        MyMSG.exec();
    }
}


void personl2::on_pushButton_2_clicked()
{

    prof = QFileDialog::getOpenFileName(this, "open", "picture", "image(*.jpg)").toStdString();

}

