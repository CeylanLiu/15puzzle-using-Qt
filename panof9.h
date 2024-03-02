//9puzzle的表盘,继承自mainwindow,需要include"puzzle9.h"(9puzzle的块）
//若要换皮肤，则需要再建一个panof9skin1类，cpp代码全复制过去就完事了，我在cpp里写了相应的初始化函数给你用，有数字和图标两个版本
#ifndef PANOF9_H
#define PANOF9_H

#include <QWidget>
#include<puzzle9.h>
#include<forward_or_back.h>
#include<QTime>
#include<QTimer>
#include<QLabel>

class panof9 : public QWidget
{
    Q_OBJECT
public:
    explicit panof9(int i=0,QWidget *parent = nullptr);
    puzzle9 *mybtn[3][3];//panof9特有的数据成员

    FB *back;
    FB *restart;
    QLabel *label1;
    QFont Ft1;
    QFont Ft2;//计数部分
    QLabel *time1;
    int getstep();
private slots:
    void update();
    void text();
    void countdown();
private:
    bool changetime;
    bool start;
    int skin_id;
    int step;
    QTimer *timer;
    QTime   time0;//计时部分
};

#endif // PANOF9_H
