#include<settlement.h>

#include"QDebug"
#include<QLabel>

settlement::settlement(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(1100,330);

    label_of_step = new QLabel(this);
    label_of_step->move(0,200);
    label_of_step->resize(500,200);
    Ft1.setPointSize(25);
    label_of_step->setFont(Ft1);
    label_of_step->setStyleSheet("color:rgb(0,0,0);");

    label_of_time = new QLabel(this);
    label_of_time->move(500,200);
    label_of_time->resize(600,200);
    Ft2.setPointSize(25);
    label_of_time->setFont(Ft2);
    label_of_time->setStyleSheet("color:rgb(0,0,0);");

    label_of_win = new QLabel(this);
    label_of_win->move(300,0);
    label_of_win->resize(400,200);
    Ft2.setPointSize(25);
    label_of_win->setFont(Ft2);
    label_of_win->setStyleSheet("color:rgb(0,0,0);");
    setAutoFillBackground(true);  //这句一定不能少，否则图片显示不出来。
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/YOU WIN.jpg")));
    setPalette(palette);
}

