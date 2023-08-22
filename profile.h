#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include"user.h"
namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(User*& users,QWidget *parent = nullptr);
    ~profile();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::profile *ui;
    User *userp;
    string prof;
};

#endif // PROFILE_H
