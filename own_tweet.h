#ifndef OWN_TWEET_H
#define OWN_TWEET_H

#include <QWidget>
#include"user.h"
namespace Ui {
class own_tweet;
}

class own_tweet : public QWidget
{
    Q_OBJECT

public:
    explicit own_tweet(User*&users,QWidget *parent = nullptr);
    ~own_tweet();

private slots:
    void on_pushButton_clicked();



private:
    Ui::own_tweet *ui;
    User* usertm;
};

#endif // OWN_TWEET_H
