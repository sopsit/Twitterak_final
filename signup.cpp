#include "signup.h"
#include "ui_signup.h"
#include "anonymous1.h"
#include "organisation1.h"
#include "personl2.h"
#include<QPixmap>
signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->radioButton_3->setChecked(true);
    ui->radioButton_2->setChecked(true);
    ui->radioButton->setChecked(true);
    QPixmap *img = new QPixmap("C:/Users/Yasaman/Desktop/logos/logo3.png");
    ui->label->setPixmap(*img);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{

    if(ui->radioButton_3->isChecked() == true)
    {
        anonymous1 *page=new anonymous1();
        page->show();
    }
    else if(ui->radioButton_2->isChecked() == true){
        personl2 *page=new personl2();
        page->show();
    }
    else if(ui->radioButton->isChecked() == true){
        organisation1 *page=new organisation1();
        page->show();
    }
    this->close();
}

