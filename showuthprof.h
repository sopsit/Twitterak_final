#ifndef SHOWUTHPROF_H
#define SHOWUTHPROF_H

#include <QWidget>
#include"user.h"
namespace Ui {
class showuthprof;
}

class showuthprof : public QWidget
{
    Q_OBJECT

public:
    explicit showuthprof(User*&users ,QWidget *parent = nullptr);
    ~showuthprof();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::showuthprof *ui;
    User* prof;
    string uname="null";
    string follower;
    string following;
    string profile;
};

#endif // SHOWUTHPROF_H
