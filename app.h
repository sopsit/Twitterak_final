#ifndef APP_H
#define APP_H

#include <QWidget>
#include"user.h"
namespace Ui {
class app;
}

class app : public QWidget
{
    Q_OBJECT

public:
    explicit app(User*& logins,QWidget *parent = nullptr);
    ~app();
   // void set(User*);
    void print();

private slots:


    void on_pushButton_clicked();

private:
    Ui::app *ui;
    User *users;
};

#endif // APP_H
