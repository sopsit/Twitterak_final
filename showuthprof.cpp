#include "showuthprof.h"
#include "ui_showuthprof.h"
#include"user.h"
#include <QMessageBox>
showuthprof::showuthprof(User*& users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showuthprof)
{
    ui->setupUi(this);
    prof=users;


}

showuthprof::~showuthprof()
{
    delete ui;
}

void showuthprof::on_pushButton_2_clicked()
{

    ui->listWidget->clear();
    QString uname3= ui->lineEdit->text();
    string color;
    uname=uname3.toStdString();
    ui->listWidget->addItem(QString ::fromStdString( prof->get_profile(uname,color)));
    QString uname1= ui->lineEdit->text();
    string number;
    QString numbers;
    string uname2=uname1.toStdString();
    follower=prof->get_following_or_followers(uname2,number,"followers");
    numbers=QString::fromStdString(number);
    ui->label->setText(numbers);
    string id=prof->get_id(uname);
    following= prof->get_following_or_followers(uname2,number,"following");
    numbers=QString::fromStdString(number);
    if(id[0]=='O'){
        ui->label_2->setText("---");
    }
    else {
        ui->label_2->setText(numbers);
    }
    //string colors=prof->get_color();

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
    //set profile

    string add_profile=(prof->get_profilepic_file(uname));

    if(id[0]=='A'){
        add_profile=":/C:/Users/Yasaman/Desktop/profiles/user-anon.jpg";
    }
    if(add_profile=="nl"||add_profile=="" ){

        add_profile=":/C:/Users/Yasaman/Desktop/profiles/withoutprofile.jpg";
    }
    if(add_profile!="! file can not open"){
        QImage image(QString::fromStdString (add_profile));
        QImage image2 = image.scaled(1920, 1080, Qt::KeepAspectRatio);
        ui->profile->setPixmap(QPixmap::fromImage(image2));
        ui->profile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->profile->setFixedSize(200, 200);
        QRegion *region = new QRegion(0, 0, ui->profile->width(), ui->profile->height(), QRegion::Ellipse);
        ui->profile->setScaledContents(true);
        ui->profile->setMask(*region);
    }
   /* else{
          add_profile="C:/Users/Yasaman/Desktop/profiles/withoutprofile.jpg";
    }*/

}


void showuthprof::on_pushButton_clicked()
{
    if(uname!="null"){
        ui->listWidget->clear();
        string own_uname=prof->get_username(),res;
        res=prof->follow_unfollow(own_uname,uname);
        QMessageBox MyMSG;
        MyMSG.setText(QString::fromStdString( res));
        MyMSG.exec();
        QString uname1= ui->lineEdit->text();
        string number;
        QString numbers;
        string uname2=uname1.toStdString(); string id=prof->get_id(uname);
        follower=prof->get_following_or_followers(uname2,number,"followers");
        numbers=QString::fromStdString(number);
        ui->label->setText(numbers);
        following= prof->get_following_or_followers(uname2,number,"following");
        numbers=QString::fromStdString(number);

        string color;
         ui->listWidget->addItem(QString ::fromStdString( prof->get_profile(uname,color)));
        if(id[0]=='O'){
            ui->label_2->setText("---");
        }
        else {
            ui->label_2->setText(numbers);
        }
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
        else if(color=="gray"){
            ui->label_5->setStyleSheet("background-color: gray");

        }
        //set profile

        string add_profile=(prof->get_profilepic_file(uname));
        //string Id= prof->get_id(uname);//C:/Users/Yasaman/Desktop/profiles/user-anon.jpg
        cout<<add_profile;
        if(id[0]=='A'){
            add_profile="C:/Users/Yasaman/Desktop/profiles/user-anon.jpg";
        }
        if(add_profile=="null"){

            add_profile="C:/Users/Yasaman/Desktop/profiles/withoutprofile.jpg";
        }
        if(add_profile!="! file can not open"){
            QImage image(QString::fromStdString (add_profile));
            QImage image2 = image.scaled(1920, 1080, Qt::KeepAspectRatio);
            ui->profile->setPixmap(QPixmap::fromImage(image2));
            ui->profile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            ui->profile->setFixedSize(200, 200);
            QRegion *region = new QRegion(0, 0, ui->profile->width(), ui->profile->height(), QRegion::Ellipse);
            ui->profile->setScaledContents(true);
            ui->profile->setMask(*region);
        }
    }
}


void showuthprof::on_pushButton_3_clicked()
{
    this->close();
}

