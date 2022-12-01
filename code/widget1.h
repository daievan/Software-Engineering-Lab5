#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>

namespace Ui {   //新增的
 class Form;
}

class Widget1 : public QWidget
{
    Q_OBJECT

    public:
    Widget1(QWidget *parent = nullptr);

    ~Widget1();

    private :
    Ui::Form *ff;   //新增的
};

#endif // WIDGET1_H
