#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"user.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr );
    ~login();



private slots:
    //    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    User* logins;
};

#endif // LOGIN_H
