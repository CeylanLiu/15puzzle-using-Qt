#ifndef SKIN_H
#define SKIN_H

#include<skin_Button.h>
#include<forward_or_back.h>
#include<QWidget>
#include<QLabel>


class skin:public QWidget
{
    Q_OBJECT
public:
    explicit skin(QWidget *parent = nullptr);
    QLabel *showlabel;
    skin_Button *skin1;
    skin_Button *skin2;
    skin_Button *skin3;
    skin_Button *skin4;
    FB *back;
private slots:
    void showskin_1();
    void showskin_2();
    void showskin_3();
    void showskin_4();
    void noshowskin();
};

#endif // SKIN_H
