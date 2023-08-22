#include "myprofile.h"
#include "ui_myprofile.h"
#include"user.h"
#include<qlistwidget.h>
#include<QPainter>
#include<QImage>
MyProfile::MyProfile(User*& users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyProfile)
{
    ui->setupUi(this);
    Myprofile=users;

    //set profile
    string uname=Myprofile->get_username(), color;
    string add_profile=(Myprofile->get_profilepic_file(uname));
    string id= Myprofile->get_id(uname);//C:/Users/Yasaman/Desktop/profiles/user-anon.jpg

    if(id[0]=='A'){
        add_profile=":/C:/Users/Yasaman/Desktop/profiles/user-anon.jpg";
    }
   // cout<<add_profile;
    if(add_profile=="null" ||add_profile=="nl"||add_profile=="" ){
        add_profile=":/C:/Users/Yasaman/Desktop/profiles/withoutprofile.jpg";
    }
    if(add_profile!="! file can not open"){
        QImage image(QString::fromStdString (add_profile));
        QImage image2 = image.scaled(1080, 1920, Qt::KeepAspectRatio);
        ui->profile->setPixmap(QPixmap::fromImage(image2));
        ui->profile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->profile->setFixedSize(200, 200);
        QRegion *region = new QRegion(0, 0, ui->profile->width(), ui->profile->height(), QRegion::Ellipse);
        ui->profile->setScaledContents(true);
        ui->profile->setMask(*region);
    }

    //set follower and followings

    ui->listWidget->addItem(QString ::fromStdString(Myprofile->get_profile(uname,color)));
    string number;
    QString numbers;
    follower=Myprofile->get_following_or_followers(uname,number,"followers");
    numbers=QString::fromStdString(number);
    ui->label->setText(numbers);
    following= Myprofile->get_following_or_followers(uname,number,"following");
    numbers=QString::fromStdString(number);
    ui->label_2->setText(numbers);



    //set color of header

    if(color=="red"){

       ui->label_5->setStyleSheet("background-color: red");

    }
    else if(color=="pink"){

       ui->label_5->setStyleSheet("background-color: pink");
    }
    else if(color=="purple"){
       ui->label_5->setStyleSheet("background-color: purple");

    }
    else if(color=="blue"){
       ui->label_5->setStyleSheet("background-color: blue");

    }
    else if(color=="black"){
       ui->label_5->setStyleSheet("background-color: black");

    }
    else if(color=="yellow"){
       ui->label_5->setStyleSheet("background-color: yellow");

    }
    else if(color=="orange"){
       ui->label_5->setStyleSheet("background-color: orange");

    }
    else if(color=="green"){
                    ui->label_5->setStyleSheet("background-color: green");
               }
}


MyProfile::~MyProfile()
{
    delete ui;
}

void MyProfile::on_follower_clicked()
{
    string uname=Myprofile->get_username(),number;
    ui->listWidget_2->addItem(QString ::fromStdString(Myprofile->get_following_or_followers(uname,number,"followers")));
}


void MyProfile::on_following_clicked()
{
    string uname=Myprofile->get_username(),number;
    ui->listWidget_3->addItem(QString ::fromStdString(Myprofile->get_following_or_followers(uname,number,"following")));
}


void MyProfile::on_pushButton_clicked()
{
    this->close();
}

