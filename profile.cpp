#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include <QMessageBox>
#include<QFileDialog>
profile::profile(User*& users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    userp=users;
    ui->radioButton->setChecked(true);//country
    ui->radioButton_2->setChecked(true);//orgusername
    ui->radioButton_3->setChecked(true);//username
    ui->radioButton_4->setChecked(true);//pass
    ui->radioButton_5->setChecked(true);//phone
    ui->radioButton_6->setChecked(true);//bio
    ui->radioButton_7->setChecked(true);//birthday
    ui->radioButton_8->setChecked(true);//color
    ui->radioButton_9->setChecked(true);//name
    ui->radioButton_10->setChecked(true);//link
    ui->radioButton_11->setChecked(true);//profile photo
    ui->radioButton_12->setChecked(true);//organisation_username



}

profile::~profile()
{
    delete ui;
}


void profile::on_pushButton_clicked()
{
    QString edit=ui->lineEdit->text();
    string edit_txt=edit.toStdString(),uname=userp->get_username(),res;
    if(ui->radioButton->isChecked() == true){
         res=userp->edit_link_country_color(uname,edit_txt,"country");

    }
    else if(ui->radioButton_2->isChecked() == true){

         res=userp->edit_Organization_Username(uname,edit_txt);
    }
    else if(ui->radioButton_3->isChecked()==true){
         res=userp->edit_username(uname,edit_txt);
    }
    else if(ui->radioButton_4->isChecked()==true){
         res=userp->edit_password(uname,edit_txt);
    }
    else if(ui->radioButton_5->isChecked()==true){
         res=userp->edit_phonenumber(uname,edit_txt);
    }
    else if(ui->radioButton_6->isChecked()==true){
         res=userp->edit_bio(uname,edit_txt);
    }
    else if(ui->radioButton_7->isChecked()==true){
         res=userp->edit_date(uname,edit_txt);
    }
    else if(ui->radioButton_8->isChecked()==true){
         res=userp->edit_link_country_color(uname,edit_txt,"color");
    }
    else if(ui->radioButton_9->isChecked()==true){
         res=userp->edit_name(uname, edit_txt);
    }
    else if(ui->radioButton_10->isChecked()==true){
         res=userp->edit_link_country_color(uname,edit_txt,"link");
    }
    else if(ui->radioButton_11->isChecked()==true){
         res=userp->edit_profile(uname,prof);
    }
    else if(ui->radioButton_12->isChecked()==true){
         res=userp->edit_organization1_Username(uname,edit_txt);
    }
    QMessageBox MyMSG;
    MyMSG.setWindowTitle("Edit");
    MyMSG.setText(QString::fromStdString( res));
    MyMSG.exec();
    this->close();
}


void profile::on_pushButton_2_clicked()
{
    prof = QFileDialog::getOpenFileName(this, "open", "picture", "image(*.jpg)").toStdString();
}


void profile::on_pushButton_3_clicked()
{
    this->close();
}

