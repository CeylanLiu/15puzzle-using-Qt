#include "home_page.h"
#include<forward_or_back.h>

home_page::home_page(QWidget *parent) :
    QWidget(parent)
{
    start16=new FB;
    start16->setParent(this);
    start16->resize(154,154);
    start16->move(198,644);
    start16->setFont(QFont("宋体",35));
    start16->setIcon(QIcon(":/picture/puzzle15.png"));
    start16->setIconSize(QSize(154,154));
    start9=new FB;
    start9->setParent(this);
    start9->resize(160,156);
    start9->move(675,640);
    start9->setIcon(QIcon(":/picture/puzzle9.png"));
    start9->setIconSize(QSize(159,159));
    this->resize(1000,1000);
    connect(start9,&QPushButton::clicked,start9,&FB::forward_9);
    connect(start16,&QPushButton::clicked,start16,&FB::forward_16);
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/11.png")));
    setPalette(palette);
}


home_page::~home_page()
{
}
