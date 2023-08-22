#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "signup.h"

#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap *img = new QPixmap("C:/Users/Yasaman/Desktop/logos/logo3.png");
    ui->label->setPixmap(*img);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
    signup *page=new signup();
    page->show();
     this->close();
}


void MainWindow::on_pushButton_clicked()
{
    login *page=new login();
    page->show();
    this->close();
}

