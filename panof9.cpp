#include "panof9.h"
#include<QPushButton>
#include<QLabel>
#include"QDebug"
#include<settlement.h>

panof9::panof9(int j,QWidget *parent) : skin_id(j),QWidget(parent)
{
    changetime=0;
    start=0;
    step=0;
    puzzle9 tmp;
    srand((unsigned int)time(NULL));
    //打乱
    for(int x1=0,y1=0,x2=0,y2=0,i=0;i<=99;i++)
    {
        x1= rand() %3;
        x2= rand() %3;
        y1= rand() %3;
        y2= rand() %3;

        tmp.swap(&puzzle9::c[x1+1][y1+1],&puzzle9::c[x2+1][y2+1]);
    }//第一次打乱
    int c1[3][3];//此数组左右是用于判断打乱是否可还原
    for (int x=0;x<3;x++) {
        for(int y=0;y<3;y++)
            c1[x][y]=puzzle9::c[x+1][y+1];
    }//从c读入c1
    bool ans=tmp.isSolvable(c1);
    while(!ans){//如果不能还原，就再打乱一次
        for(int x1=0,y1=0,x2=0,y2=0,i=0;i<=2;i++)
        {
            x1= rand() %3;
            x2= rand() %3;
            y1= rand() %3;
            y2= rand() %3;

            tmp.swap(&puzzle9::c[x1+1][y1+1],&puzzle9::c[x2+1][y2+1]);
        }//打乱
        for (int x=0;x<3;x++) {
            for(int y=0;y<3;y++)
                c1[x][y]=puzzle9::c[x+1][y+1];
        }
        ans=tmp.isSolvable(c1);
    }
    //设置block状态
    int i=1;
    puzzle9 *mybtn[3][3];
    for (int y=0;y<=2;y++) {
        for(int x=0;x<=2;x++){
            mybtn[x][y]=new puzzle9;
            mybtn[x][y]->setnum(puzzle9::c[y+1][x+1]);
            i++;
            mybtn[x][y]->settx(y);
            mybtn[x][y]->setty(x);

            connect(mybtn[x][y],SIGNAL(enterEvent_2()),this,SLOT(countdown()));
            connect(mybtn[x][y],SIGNAL(enterEvent_2()),this,SLOT(text()));

            if(puzzle9::c[y+1][x+1]==0){
                mybtn[x][y]->setText("");
                mybtn[x][y]->setStyleSheet("font-size:200px;background-color:rgb(255, 255, 255)");
            }
            else if(puzzle9::c[y+1][x+1]==1){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(246, 184, 161)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);
            }
            else if(puzzle9::c[y+1][x+1]==2){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(246, 184, 161)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==3){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(246, 184, 161)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==4){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(243, 111, 106)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==5){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(251, 219, 118)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(30, 120, 172)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(125, 156, 187);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==6){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(251, 219, 118)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(30, 120, 172)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(125, 156, 187);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==7){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(243, 111, 106)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 90, 79);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle9::c[y+1][x+1]==8){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(246, 180, 86)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(30, 120, 172)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(125, 156, 187);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            mybtn[x][y]->resize(200,200);
            mybtn[x][y]->move(mybtn[x][y]->getty()*200,mybtn[x][y]->gettx()*200);
        }
    }


    back=new FB;
    back->setText("back");
    back->setParent(this);
    back->resize(500,200);
    back->setFont(QFont("宋体",35));
    back->move(750,1000);


    restart=new FB;
    restart->setText("restart");
    restart->setParent(this);
    restart->resize(500,200);
    restart->setFont(QFont("宋体",35));
    restart->move(250,1000);

    label1 = new QLabel(this);
    label1->setText("the step");
    label1->move(1100,0);
    label1->resize(400,200);
    Ft1.setPointSize(25);

    label1->setFont(Ft1);
    label1->setStyleSheet("color:rgb(0,0,0);");

    time1 = new QLabel(this);
    time1->move(1100,200);
    time1->resize(400,200);
    Ft2.setPointSize(25);
    time1->setText("00:15:000");
    time1->setFont(Ft2);

    time0.setHMS(0,0,15,0);//设置初始值
    timer = new QTimer(this);//创建一个定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);


    connect(back,&QPushButton::clicked,back,&FB::back_16);
    if(skin_id==0)
        connect(restart,&QPushButton::clicked,restart,&FB::rebuildof9);
    else if(skin_id==1)
        connect(restart,&QPushButton::clicked,restart,&FB::rebuildof9_1);
    else if(skin_id==2)
        connect(restart,&QPushButton::clicked,restart,&FB::rebuildof9_2);
    else if(skin_id==3)
        connect(restart,&QPushButton::clicked,restart,&FB::rebuildof9_3);

    if(skin_id==0)
    {
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/targetof8.jpg")));
    setPalette(palette);
    }
    else if(skin_id==1)
    {
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/Target4.png")));
    setPalette(palette);
    }
    else if(skin_id==2)
    {
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/Target5.png")));
    setPalette(palette);
    }
    else if(skin_id==3)
    {
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/Target6.png")));
    setPalette(palette);
    }
    this->setFixedSize(1500,1300);
}



void panof9::text()
{

    step+=1;
    if(puzzle9::c[1][1]==1&&
       puzzle9::c[1][2]==2&&
       puzzle9::c[1][3]==3&&
       puzzle9::c[2][1]==4&&
       puzzle9::c[2][2]==5&&
       puzzle9::c[2][3]==6&&
       puzzle9::c[3][1]==7&&
       puzzle9::c[3][2]==8
       )
    {
    label1->setText(QString::number(step));
    timer->stop();
    settlement *w=new settlement();
    w->show();
    w->label_of_step->setStyleSheet("#label{border:2px solid rgb(255,255,255);border-top-left-radius: 5px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 5px;}");
    w->label_of_step->setText(tr("The final step:").append(QString::number(step)));
    w->label_of_time->setStyleSheet("#label{border:2px solid rgb(255,255,255);border-top-left-radius: 5px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 5px;}");
    w->label_of_time->setText(tr("The final time:").append(time0.toString("mm:ss:zzz")));
    }
}

void panof9::update()
{
    if(start==0 && time0.second()==0)
    {
        start=1;
        changetime=1;
        timer->stop();
        time0.setHMS(0,0,0,0);
        timer->start(10);
    }
    static quint32 time_out=0;
    time_out++;
    if(changetime==0)
        time0=time0.addSecs(-1);
    else if(changetime!=0)
        time0=time0.addMSecs(10);
    time1->setText(time0.toString("mm:ss:zzz"));
}

void panof9::countdown()
{
    if(start==0)
    {
        start=1;
        changetime=1;
        timer->stop();
        time0.setHMS(0,0,0,0);
        timer->start(10);
    }
}

int panof9::getstep()
{
    return step;
}




