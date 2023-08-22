#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include"user.h"
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    User *signups;
    Ui::signup *ui;
};

#endif // SIGNUP_H
