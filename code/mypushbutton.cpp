#include "mypushbutton.h"
#include"QDebug"
#include<QPropertyAnimation>
//MypushButton::MypushButton(QWidget *parent) : QPushButton(parent)
//{

//}
MypushButton::MypushButton(QString normalImg,QString pressImg ){
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug() << "图片加载失败";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void MypushButton::zoom1(){

    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
void MypushButton::zoom2(){

    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
