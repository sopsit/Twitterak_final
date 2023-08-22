#include "organisation1.h"
#include "ui_organisation1.h"
#include "organisation.h"
#include "app.h"
#include"user.h"
#include <iostream>
#include "QMessageBox"
#include<QFileDialog>
using namespace std;
organisation1::organisation1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organisation1)
{
    ui->setupUi(this);
    //orga=signups;
}

organisation1::~organisation1()
{
    delete ui;
}

void organisation1::on_pushButton_clicked()
{
    QString a,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    string b,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,res;
    a=ui->lineEdit->text();//username
    a2=ui->lineEdit_11->text();//pass
    a3=ui->lineEdit_8->text();//color
    a4=ui->lineEdit_4->text();//country
    a5=ui->lineEdit_5->text();//color
    a6=ui->lineEdit_6->text();//phone
    a7=ui->lineEdit_7->text();//bio
    a8=ui->lineEdit_8->text();//org uname
    a9=ui->lineEdit_9->text();//name
    a10=ui->lineEdit_10->text();//link
    b=a.toStdString();
    b2=a2.toStdString();
    b3= a3.toStdString();
    b4=a4.toStdString();
    b5=a5.toStdString();
    b6=a6.toStdString();
    b7=a7.toStdString();
    b8=a8.toStdString();
    b9=a9.toStdString();
    b10=a10.toStdString();
    organisation temp;
    res=temp.signup(b,b2,b9,b6,b7,b4,b10,b5,b8,prof);
    cout<<res;
    if(res=="! You have successfully signed up."){
        orga=new organisation;
        orga->set_username(b);
        orga->set_password(b2);
        //orga=&temp;
        app *page=new app(orga);
        page->show();
    }
    else{
        QMessageBox MyMSG;
        MyMSG.setText(QString::fromStdString(res));
        MyMSG.exec();
    }

}


void organisation1::on_pushButton_2_clicked()
{
    prof = QFileDialog::getOpenFileName(this, "open", "picture", "image(*.jpg)").toStdString();

}

