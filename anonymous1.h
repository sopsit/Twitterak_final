#ifndef ANONYMOUS1_H
#define ANONYMOUS1_H

#include <QWidget>
#include "user.h"
namespace Ui {
class anonymous1;
}

class anonymous1 : public QWidget
{
    Q_OBJECT

public:
    explicit anonymous1(QWidget *parent = nullptr);
    ~anonymous1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::anonymous1 *ui;
    User * anonymouses;
};

#endif // ANONYMOUS1_H
