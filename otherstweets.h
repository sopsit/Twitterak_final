#ifndef OTHERSTWEETS_H
#define OTHERSTWEETS_H

#include <QWidget>
#include"user.h"
namespace Ui {
class othersTweets;
}

class othersTweets : public QWidget
{
    Q_OBJECT

public:
    explicit othersTweets(User*& users,QWidget *parent = nullptr);
    ~othersTweets();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_4_clicked();


    void on_add_mention_clicked();

    void on_like_tweet_clicked();

    void on_add_mention_2_clicked();

    void on_retweet_clicked();

    void on_qoute_clicked();

private:
    Ui::othersTweets *ui;
    User* othTweets;
    string username;
};

#endif // OTHERSTWEETS_H
