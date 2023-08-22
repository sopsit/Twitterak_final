#ifndef ORGANISATION1_H
#define ORGANISATION1_H

#include <QWidget>
#include "user.h"

namespace Ui {
class organisation1;
}

class organisation1 : public QWidget
{
    Q_OBJECT

public:
    explicit organisation1(QWidget *parent = nullptr);
    ~organisation1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::organisation1 *ui;
    User* orga;
    string prof;
};

#endif // ORGANISATION1_H
