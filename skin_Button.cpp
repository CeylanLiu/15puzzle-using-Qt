#include "skin_Button.h"
#include<panof9.h>
#include<pan.h>

skin_Button::skin_Button(QWidget *parent) : QPushButton(parent)
{
}

void skin_Button::enterEvent(QEvent *)
{
       emit enterEvent_1();
}

void skin_Button::leaveEvent(QEvent *)
{
       emit leaveEvent_1();
}

void skin_Button::changeskin_pan_0()
{
   pan *text = new pan();
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_1()
{
   pan *text = new pan(1);
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_2()
{
   pan *text = new pan(2);
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_3()
{
   pan *text = new pan(3);
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_0_of9()
{
   panof9 *text = new panof9();
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_1_of9()
{
   panof9 *text = new panof9(1);
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_2_of9()
{
   panof9 *text = new panof9(2);
   parentWidget()->close();
   text->show();
}

void skin_Button::changeskin_pan_3_of9()
{
   panof9 *text = new panof9(3);
   parentWidget()->close();
   text->show();
}


