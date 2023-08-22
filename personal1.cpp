#include "personal1.h"
#include "ui_personal.h"

Personal::Personal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Personal)
{
    ui->setupUi(this);
}

Personal::~Personal()
{
    delete ui;
}
