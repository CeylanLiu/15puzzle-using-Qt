#include "skinof9.h"
#include<panof9.h>
#include<QLabel>

skinof9::skinof9(QWidget *parent) :
    QWidget(parent)
{

    this->resize(1200,1000);


    showlabel = new QLabel(this);
    showlabel->move(0,0);
    showlabel->resize(1000,1000);

    skin1=new skin_Button;
    skin1->setIcon(QIcon(":/picture/moren.jpg"));
    skin1->setIconSize(QSize(200,200));
    skin1->setParent(this);
    skin1->resize(200,200);
    skin1->setFont(QFont("宋体",25));
    skin1->move(1000,0);

    skin2=new skin_Button;
    skin2->setIcon(QIcon(":/picture/jingdian.jpg"));
    skin2->setIconSize(QSize(200,200));
    skin2->setParent(this);
    skin2->resize(200,200);
    skin2->setFont(QFont("宋体",25));
    skin2->move(1000,200);

    skin3=new skin_Button;
    skin3->setIcon(QIcon(":/picture/gudian.jpg"));
    skin3->setIconSize(QSize(200,200));
    skin3->setParent(this);
    skin3->resize(200,200);
    skin3->setFont(QFont("宋体",25));
    skin3->move(1000,400);

    skin4=new skin_Button;
    skin4->setIcon(QIcon(":/picture/caihong.jpg"));
    skin4->setIconSize(QSize(200,200));
    skin4->setParent(this);
    skin4->resize(200,200);
    skin4->setFont(QFont("宋体",25));
    skin4->move(1000,600);

    back=new FB;
    back->setIcon(QIcon(":/picture/BACKBUTTON.jpg"));
    back->setIconSize(QSize(200,200));
    back->setParent(this);
    back->resize(200,200);
    back->setFont(QFont("宋体",25));
    back->move(1000,800);


    connect(skin1,SIGNAL(enterEvent_1()),this,SLOT(showskin_1()));
    connect(skin1,SIGNAL(leaveEvent_1()),this,SLOT(noshowskin()));
    connect(skin2,SIGNAL(enterEvent_1()),this,SLOT(showskin_2()));
    connect(skin2,SIGNAL(leaveEvent_1()),this,SLOT(noshowskin()));
    connect(skin3,SIGNAL(enterEvent_1()),this,SLOT(showskin_3()));
    connect(skin3,SIGNAL(leaveEvent_1()),this,SLOT(noshowskin()));
    connect(skin4,SIGNAL(enterEvent_1()),this,SLOT(showskin_4()));
    connect(skin4,SIGNAL(leaveEvent_1()),this,SLOT(noshowskin()));
    connect(skin1,&QPushButton::clicked,skin1,&skin_Button::changeskin_pan_1_of9);
    connect(skin2,&QPushButton::clicked,skin2,&skin_Button::changeskin_pan_2_of9);
    connect(skin3,&QPushButton::clicked,skin3,&skin_Button::changeskin_pan_3_of9);
    connect(skin4,&QPushButton::clicked,skin4,&skin_Button::changeskin_pan_0_of9);
    connect(back,&QPushButton::clicked,back,&FB::back_9);
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/BACK.jpg")));
    setPalette(palette);
}

void skinof9::showskin_1()
{
    QImage image(QString(":/picture/moren5.png"));
    this->showlabel->setPixmap(QPixmap::fromImage(image));
    this->showlabel->setScaledContents(true);
}

void skinof9::showskin_2()
{
    QImage image(QString(":/picture/jingdian5.png"));
    this->showlabel->setPixmap(QPixmap::fromImage(image));
    this->showlabel->setScaledContents(true);
}

void skinof9::showskin_3()
{
    QImage image(QString(":/picture/gudian5.png"));
    this->showlabel->setPixmap(QPixmap::fromImage(image));
    this->showlabel->setScaledContents(true);
}
void skinof9::showskin_4()
{
    QImage image(QString(":/picture/9.png"));
    this->showlabel->setPixmap(QPixmap::fromImage(image));
    this->showlabel->setScaledContents(true);
}
void skinof9::noshowskin()
{
    this->showlabel->clear();
}
