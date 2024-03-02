#include "mainwindow.h"
#include<QPushButton>
#include <QApplication>
#include<block.h>
#include<iostream>
#include"pan.h"
#include"home_page.h"
#include"puzzle15.h"
#include"puzzle9.h"
#include"panof9.h"
#include<skin.h>
//同一时刻只能存在一个15puzzle表盘和一个9puzzle表盘，如果同时存在两个15puzzle，下面公用的静态数组会乱掉
int puzzle15::b[6][6]={1,1,1,1,1,1,1,1,2,3,4,1,1,5,6,7,8,1,1,9,10,11,12,1,1,13,14,15,0,1,1,1,1,1,1,1};
int puzzle9::c[5][5]={1,1,1,1,1,1,1,2,3,1,1,4,5,6,1,1,7,8,0,1,1,1,1,1,1};
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    home_page w1;
    w1.show();
    return a.exec();
}
