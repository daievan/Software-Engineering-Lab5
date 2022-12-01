#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPushButton>
#include"mypushbutton.h"
#include<QTimer>
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(2700,1600);

    setWindowIcon(QIcon(":/res/R-C.png"));
    setWindowTitle("人工确认等价性工具");

    //开始按钮
    MypushButton * startBtn = new MypushButton(":/res/button-start.png");
    startBtn->setParent(this);
    startBtn->move(1150,800);

    //实例化第二个场景
    comparScene = new Widget1;

    connect(startBtn,&MypushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(800,this,[=](){
            this->hide();

            comparScene->show();
        });

    });
}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


MainScene::~MainScene()
{
    delete ui;
}
