#ifndef PERSONL2_H
#define PERSONL2_H

#include <QWidget>
#include "user.h"
namespace Ui {
class personl2;
}

class personl2 : public QWidget
{
    Q_OBJECT

public:
    explicit personl2(QWidget *parent = nullptr);
    ~personl2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::personl2 *ui;
    User *personals;
    string prof;
};

#endif // PERSONL2_H
