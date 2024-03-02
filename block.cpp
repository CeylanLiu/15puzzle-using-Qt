#include "block.h"

block::block(QWidget *parent) : QPushButton(parent)
{
}
void block::mymove(){
}
void block::enterEvent(QEvent *){
    mymove();
}
void block::swap(int *x, int *y){
    int temp = *y;
    *y = *x;    //将x指针所指地址的值赋值给 y指针所指地址；*x相当于一个整数，将其赋值给指针变量所指的地址
    *x = temp;
}
void block::settx(int x){
    tx=x;
}
void block::setty(int y){
    ty=y;
}
void block::setnum(int num0){
    num=num0;
}
int block::gettx(){
    return tx;
}
int block::getty(){
    return ty;
}
int block::getnum(){
    return num;
}
