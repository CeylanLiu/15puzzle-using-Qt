//block继承自QPushButton，每一个pan里面的block都是一个具体的块
#ifndef BLOCK_H
#define BLOCK_H

#include<QPushButton>
#include <QObject>
#include <QEvent> // 添加头文件
#include <QApplication> // 添加头文件

class block : public QPushButton
{
    Q_OBJECT
private:
    int tx=0;//记录x坐标，并以此为依据设置x偏移量
    int ty=0;//记录y坐标，并以此为依据设置y偏移量
    int num;//对应的数据
public:
    explicit block(QWidget *parent = nullptr);
    void swap(int *x, int *y);//不需要是虚函数，swap对于每个类操作都是一样的
    virtual void enterEvent(QEvent *);//必须是虚函数，因为里面调用了每个类对应的不同的函数mymove()
    void settx(int x);
    void setty(int y);
    void setnum(int num0);
    int gettx();
    int getty();
    int getnum();
signals:
    void enterEvent_1();
    void enterEvent_2();
public:
    virtual void mymove();//这是个虚函数
};

#endif // BLOCK_H

