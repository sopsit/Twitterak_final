#ifndef PERSONAL1_H
#define PERSONAL1_H

#include <QWidget>

namespace Ui {
class Personal;
}

class Personal : public QWidget
{
    Q_OBJECT

public:
    explicit Personal(QWidget *parent = nullptr);
    ~Personal();

private:
    Ui::Personal *ui;
};

#endif // PERSONAL1_H
