#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MypushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MypushButton(QWidget *parent = nullptr);
    //
    MypushButton(QString normalImg,QString pressImg="");

    QString normalImgPath;
    QString pressImgPath;

    void zoom1();//向下跳
    void zoom2();//向上跳

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
