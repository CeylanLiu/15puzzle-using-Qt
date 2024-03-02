//15puzzle的表盘，继承自mainwindow，需要include"puzzle15.h"（15puzzle的块）
//若要换皮肤，则需要再建一个panskin1类，cpp代码全复制过去就完事了，我在cpp里写了相应的初始化函数给你用，有数字和图标两个版本
#ifndef PAN_H
#define PAN_H

#include <QWidget>
#include<puzzle15.h>
#include<forward_or_back.h>
#include<QTime>
#include<QTimer>
#include<QLabel>

class QLabel;

class pan : public QWidget
{
    Q_OBJECT
public:
    explicit pan(int i=0,QWidget *parent = nullptr);
    puzzle15 *mybtn[4][4];//pan特有的数据成员
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

#endif // PAN_H
