#ifndef MYPROFILE_H
#define MYPROFILE_H

#include <QWidget>
#include"user.h"

namespace Ui {
class MyProfile;
}

class MyProfile : public QWidget
{
    Q_OBJECT

public:
    explicit MyProfile(User*& users,QWidget *parent = nullptr);
    ~MyProfile();

private slots:
    void on_follower_clicked();

    void on_following_clicked();

    void on_pushButton_clicked();

private:
    Ui::MyProfile *ui;
    User* Myprofile;
    string follower;
    string following;
};

#endif // MYPROFILE_H
