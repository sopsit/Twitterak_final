#ifndef SEARCH1_H
#define SEARCH1_H

#include <QWidget>

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private:
    Ui::search *ui;
};

#endif // SEARCH1_H
