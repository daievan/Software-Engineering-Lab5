#include "widget1.h"
#include "QPushButton"
#include "ui_form.h"   //新增的
#include <QLabel>
#include<QFileDialog>
#include<QFile>
#include<QTextCodec>
#include"mypushbutton.h"
#include<QPainter>
#include<QPushButton>
#include<QTimer>
#include<QDebug>
#include<QMessageBox>
#include<QTextStream>

Widget1::Widget1(QWidget *parent)
    : QWidget(parent),ff(new Ui::Form)  //新增的

{
    //QPushButton *a=new QPushButton(this);
    ff->setupUi(this);
    setFixedSize(2700,1600);

    setWindowIcon(QIcon(":/res/R-C.png"));
    setWindowTitle("人工确认等价性工具");
    connect(ff->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\dai\\Desktop\\SE-needed-files\\");
        ff->lineEdit->setText(path);
        QTextCodec * codec  = QTextCodec::codecForName("gbk");
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        ff->textEdit->setText(codec->toUnicode(array));
    });
    connect(ff->pushButton_3,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\dai\\Desktop\\SE-needed-files\\");
        ff->lineEdit_3->setText(path);
        QTextCodec * codec  = QTextCodec::codecForName("gbk");
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        ff->textEdit_2->setText(codec->toUnicode(array));
    });
    MypushButton * startBtn = new MypushButton(":/res/result.png");
    startBtn->setParent(this);
    startBtn->move(600,1470);

    MypushButton * startBtn1 = new MypushButton(":/res/confirm.png");
    startBtn1->setParent(this);
    startBtn1->move(2000,1470);

    //弹出提示消息
    //QString c1,c2,c3;
    //char c1[500];
    connect(startBtn1,&MypushButton::clicked,[=](){
        QFile file("E://Qt_Files//os_ui//result.txt");
            file.open( QIODevice::ReadWrite | QIODevice::Append);
            QTextStream out(&file);
            QString c1 =ff->lineEdit->text().mid(40,-1);
            QString c2 =ff->lineEdit_3->text().mid(40,-1);
            QString c3;
            if(!ff->lineEdit->text().isEmpty() && !ff->lineEdit_3->text().isEmpty()){

                out << ff->lineEdit->text().mid(40,-1);
                out << "        ";
                out << ff->lineEdit_3->text().mid(40,-1);
                out << "        ";
                out << "judgement: ";

                QObjectList list = ff->groupBox->children();
                foreach(QObject* obj,list){
                    QRadioButton* a=(QRadioButton*)obj;
                    if (a->isChecked()){
                        //qDebug()<<a->text();
                        QString c4=a->text();
                        c3=c4;
                        out << a->text();
                     if(QString::compare(c3,"等价")==0){
                         //qDebug()<<"sss";
                         c3="equivalence";
                     }
                     else if(QString::compare(c3,"不等价")==0){
                         //qDebug()<<"kkk";
                         c3="inequivalence";
                     }
                     else if(QString::compare(c3,"存疑")==0){
                         //qDebug()<<"ppp";
                         c3="doubtful";
                     }
                        out << "\n";
                    }
                }
                file.close();

            }


        QMessageBox::information(this,"提示","你的结果已存入本目录下的result.txt中");
        QFile file1("E://Qt_Files//os_ui//程序判断结果.txt");
            if(file1.open(QIODevice::ReadOnly))
            {
               char buffer[2048];
               //读取所有内容
               //QByteArray bytearr = file.readAll();
               // qDebug()<<  "all" << bytearr;
               //逐行读取内容
               while(!file1.atEnd()){
                   qint64 lineLen = file1.readLine(buffer,sizeof(buffer));
                   //qDebug()<< "b1" <<lineLen;
                   if(lineLen!=-1)
                   {
                       //qDebug()<< "b1" <<buffer;
                       char *token;
                          const char s[2] = "|";
                          /* 获取第一个子字符串 */
                          token = strtok(buffer,s);
                          QString s1=(QString) token;
                          token = strtok(NULL,s);
                          QString s2=(QString) token;
                          token = strtok(NULL,s);
                          QString s3=(QString) token;
                          s3=s3.simplified();
                          //qDebug()<< s1;
                          //qDebug()<< s2;
                          //qDebug()<< s3;
                          if(QString::compare(c1,s1)==0&&QString::compare(c2,s2)==0){
                              //qDebug()<< c3;
                              //qDebug()<< s3;
                              if(QString::compare(c3,s3)==0){
                                  QMessageBox::information(this,"提示","与程序判断的结果一致,请自行选择下面需要判断的程序对");
                                  ff->lineEdit->clear();
                                  ff->lineEdit_3->clear();
                                  ff->textEdit->clear();
                                  ff->textEdit_2->clear();
                                  ff->radioButton->setChecked(true);
                                  //ff->radioButton_2->setChecked(true);
                                  //ff->radioButton_3->setChecked(true);


                              }
                              else{
                                    QMessageBox::information(this,"提示","与程序判断的结果不一致,下一次判断请优先选择与此次关联的程序对");
                                    //ff->radioButton->setChecked(true);
                              }
                          }

                   }
               }

            }
            file1.close();

    });
}

Widget1::~Widget1()
{

}
