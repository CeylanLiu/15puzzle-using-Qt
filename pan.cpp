#include "pan.h"
#include<QPushButton>
#include<QLabel>
#include"QDebug"
#include<settlement.h>


pan::pan(int j,QWidget *parent) : skin_id(j),QWidget(parent)
{
    changetime=0;
    start=0;
    step=0;
    puzzle15 tmp;
    srand((unsigned int)time(NULL));
    //打乱
    int a[16];
    int inv = 0;
    for(int x1=0,y1=0,x2=0,y2=0,i=0;i<=99;i++)
    {
        x1= rand() %4;
        x2= rand() %4;
        y1= rand() %4;
        y2= rand() %4;
        tmp.swap(&puzzle15::b[x1+1][y1+1],&puzzle15::b[x2+1][y2+1]);
    }//第一次打乱

    for (int x=0,i=0;x<=3;x++) {
        for(int y=0;y<=3;y++,i++){
            a[i]=puzzle15::b[x+1][y+1];
        }
    }//读入a[i]
    for (int i=0; i<16; ++i)
        if (a[i])
            for (int j=0; j<i; ++j)
                if (a[j] > a[i])
                    ++inv;
    for (int i=0; i<16; ++i)
        if (a[i] == 0)
            inv += 1 + i / 4;//判断第一次打乱是否有效
    bool ans=(inv & 1) ;
    while(ans){
        inv=0;
        for(int x1=0,y1=0,x2=0,y2=0,i=0;i<=3;i++)
        {
            x1= rand() %4;
            x2= rand() %4;
            y1= rand() %4;
            y2= rand() %4;

            tmp.swap(&puzzle15::b[x1+1][y1+1],&puzzle15::b[x2+1][y2+1]);
        }//打乱
        for (int x=0,i=0;x<=3;x++) {
            for(int y=0;y<=3;y++,i++){
                a[i]=puzzle15::b[x+1][y+1];
            }
        }
        for (int i=0; i<16; ++i)
            if (a[i])
                for (int j=0; j<i; ++j)
                    if (a[j] > a[i])
                        ++inv;
        for (int i=0; i<16; ++i)
            if (a[i] == 0)
                inv += 1 + i / 4;//判断打乱是否有效
        ans=(inv & 1);//更新ans状态
    }

    //设置block状态
    int i=1;
    puzzle15 *mybtn[4][4];
    for (int y=0;y<=3;y++) {
        for(int x=0;x<=3;x++){

            mybtn[x][y]=new puzzle15;
            mybtn[x][y]->setnum(puzzle15::b[y+1][x+1]);
            i++;
            mybtn[x][y]->settx(y);
            mybtn[x][y]->setty(x);
            mybtn[x][y]->setContentsMargins(75,0,0,0);

            connect(mybtn[x][y],SIGNAL(enterEvent_1()),this,SLOT(countdown()));
            connect(mybtn[x][y],SIGNAL(enterEvent_1()),this,SLOT(text()));

            if(puzzle15::b[y+1][x+1]==0){
                mybtn[x][y]->setText("");
                mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 255, 255)");

            }
            else if(puzzle15::b[y+1][x+1]==1){
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
            else if(puzzle15::b[y+1][x+1]==2){
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
            else if(puzzle15::b[y+1][x+1]==3){
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
            else if(puzzle15::b[y+1][x+1]==4){
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
            else if(puzzle15::b[y+1][x+1]==5){
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
            else if(puzzle15::b[y+1][x+1]==6){
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
            else if(puzzle15::b[y+1][x+1]==7){
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
            else if(puzzle15::b[y+1][x+1]==8){
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
            else if(puzzle15::b[y+1][x+1]==9){
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
            else if(puzzle15::b[y+1][x+1]==10){
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
            else if(puzzle15::b[y+1][x+1]==11){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 218, 180)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(13, 173, 87)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(105, 194, 176);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle15::b[y+1][x+1]==12){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(182, 218, 180)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(13, 173, 87)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(105, 194, 176);color:rgb(255,255,255);font: bold 100px 幼圆");
                }
                mybtn[x][y]->setParent(this);}
            else if(puzzle15::b[y+1][x+1]==13){
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
            else if(puzzle15::b[y+1][x+1]==14){
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
            else if(puzzle15::b[y+1][x+1]==15){
                if(skin_id==0)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(154, 204, 151)");
                }
                else if(skin_id==1)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(13, 173, 87)");
                }
                else if(skin_id==2)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(255, 201, 111)");
                }
                else if(skin_id==3)
                {
                    mybtn[x][y]->setText(QString::number(mybtn[x][y]->getnum()));
                    mybtn[x][y]->setStyleSheet("font-size:100px;background-color:rgb(105, 194, 176);color:rgb(255,255,255);font: bold 100px 幼圆");
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
       connect(restart,&QPushButton::clicked,restart,&FB::rebuildof16);
    else if(skin_id==1)
       connect(restart,&QPushButton::clicked,restart,&FB::rebuildof16_1);
    else if(skin_id==2)
       connect(restart,&QPushButton::clicked,restart,&FB::rebuildof16_2);
    else if(skin_id==3)
       connect(restart,&QPushButton::clicked,restart,&FB::rebuildof16_3);


    this->setFixedSize(1500,1300);

    if(skin_id==0)
    {
    setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/targetof15.jpg")));
        setPalette(palette);
    }
    else if(skin_id==1)
    {
    setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/TargetOgMoren.png")));
        setPalette(palette);
    }
    else if(skin_id==2)
    {
    setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/TargetOfJingdian.png")));
        setPalette(palette);
    }
    else if(skin_id==3)
    {
    setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/picture/TargetOfGudian.png")));
        setPalette(palette);
    }
}



void pan::text()
{
    step+=1;
    if(puzzle15::b[1][2]==2&&
       puzzle15::b[1][3]==3&&
       puzzle15::b[1][4]==4&&
       puzzle15::b[2][1]==5&&
       puzzle15::b[2][2]==6&&
       puzzle15::b[2][3]==7&&
       puzzle15::b[2][4]==8&&
       puzzle15::b[3][1]==9&&
       puzzle15::b[3][2]==10&&
       puzzle15::b[3][3]==11&&
       puzzle15::b[3][4]==12&&
       puzzle15::b[4][1]==13&&
       puzzle15:: b[4][2]==14&&
       puzzle15::b[4][3]==15&&
       puzzle15::b[4][4]==0)
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

void pan::update()
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

void pan::countdown()
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

int pan::getstep()
{
    return step;
}
