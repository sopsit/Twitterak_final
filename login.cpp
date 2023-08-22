#include "login.h"
#include "ui_login.h"
#include <iostream>
#include <QMessageBox>
//#include "mainwindow.h"
#include"user.h"
#include"app.h"
#include"anonymous.h"
#include"personal.h"
#include"organisation.h"
#include<QPixmap>
using namespace std;

login::login(QWidget *parent) :
      QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap *img = new QPixmap("C:/Users/Yasaman/Desktop/logos/logo3.png");
    ui->label->setPixmap(*img);

}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    QString username=ui->textEdit->toPlainText();
    QString pass=ui->textEdit_2->toPlainText();
    string test,test2;
    test=username.toStdString();
    test2=pass.toStdString();
    User testak;
    string res=testak.login(test,test2);
    if(res!="!Password is not correct." && res!= "no user found."&& res!="not found." && res!="!Username not found."){

        if(res[0]=='A'){
            logins=new Anonymous;
            logins->set_username(test);
            logins->set_password(test2);

            app *page=new app(logins);

            page->show();

        }
        else if(res[0]=='P'){
            logins=new personal;
            //logins->set_profile(res);
            logins->set_username(test);
            logins->set_password(test2);
            app *page=new app(logins);
            page->show();
        }
        else if(res[0]=='O'){
            logins =new organisation;
            logins->set_username(test);
            logins->set_password(test2);
            string tempo=logins->get_color();
            app *page=new app(logins);
            page->show();
        }
this->close();
    }
    else{
        cout<<res;
        QMessageBox msgBox;
        msgBox.setText(QString :: fromStdString(res));
        msgBox.exec();
    }

}

