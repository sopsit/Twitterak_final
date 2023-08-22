#ifndef TWEET_H
#define TWEET_H

#include <QWidget>
#include"user.h"

namespace Ui {
class tweet;
}

class tweet : public QWidget
{
    Q_OBJECT

public:
    explicit tweet(User*& users,QWidget *parent = nullptr);
    ~tweet();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tweet *ui;
    User *usert;
};

#endif // TWEET_H
