#ifndef SKINS_H
#define SKINS_H


#include<QPushButton>

class skin_Button : public QPushButton
{
    Q_OBJECT
public:
    explicit skin_Button(QWidget *parent = nullptr);
signals:
    void enterEvent_1();
    void leaveEvent_1();
public:
    void enterEvent(QEvent *) ;
    void leaveEvent(QEvent *) ;
    void changeskin_pan_0();
    void changeskin_pan_1();
    void changeskin_pan_2();
    void changeskin_pan_3();
    void changeskin_pan_0_of9();
    void changeskin_pan_1_of9();
    void changeskin_pan_2_of9();
    void changeskin_pan_3_of9();
};

#endif // SKINS_H
