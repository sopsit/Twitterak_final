#ifndef SEARCHS_H
#define SEARCHS_H

#include <QWidget>
#include"user.h"
namespace Ui {
class searchs;
}

class searchs : public QWidget
{
    Q_OBJECT

public:
    explicit searchs(User*&users ,QWidget *parent = nullptr);
    ~searchs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::searchs *ui;
    User * userse;
};

#endif // SEARCHS_H
