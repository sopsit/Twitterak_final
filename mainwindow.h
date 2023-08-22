#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    User *users;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
