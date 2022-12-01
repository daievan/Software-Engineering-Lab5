#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"widget1.h"
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //重新paintEvant事件 画背景图
    void paintEvent(QPaintEvent *);
    Widget1 * comparScene = NULL;
private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
