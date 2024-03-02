#include<pan.h>
#include<panof9.h>
#include<skin.h>
#include<skinof9.h>
#include<home_page.h>


void FB::forward_9()
{
    skinof9 *text = new skinof9();
    parentWidget()->close();
    text->show();
}


void FB::forward_16()
{
    skin *text = new skin();
    parentWidget()->close();
    text->show();
}

void FB::back_9()
{
    home_page *text = new home_page();
    puzzle9::c[1][1]=1;
    puzzle9::c[1][2]=2;
    puzzle9::c[1][3]=3;
    puzzle9::c[2][1]=4;
    puzzle9::c[2][2]=5;
    puzzle9::c[2][3]=6;
    puzzle9::c[3][1]=7;
    puzzle9::c[3][2]=8;
    puzzle9::c[3][3]=0;
    parentWidget()->close();
    text->show();
}


void FB::back_16()
{
    home_page *text = new home_page();
    puzzle15::b[1][1]=1;
    puzzle15::b[1][2]=2;
    puzzle15::b[1][3]=3;
    puzzle15::b[1][4]=4;
    puzzle15::b[2][1]=5;
    puzzle15::b[2][2]=6;
    puzzle15::b[2][3]=7;
    puzzle15::b[2][4]=8;
    puzzle15::b[3][1]=9;
    puzzle15::b[3][2]=10;
    puzzle15::b[3][3]=11;
    puzzle15::b[3][4]=12;
    puzzle15::b[4][1]=13;
    puzzle15::b[4][2]=14;
    puzzle15::b[4][3]=15;
    puzzle15::b[4][4]=0;
    parentWidget()->close();
    text->show();
}

void FB::rebuildof16()
{
    pan *text = new pan();
    parentWidget()->close();
    text->show();
}

void FB::rebuildof16_1()
{
    pan *text = new pan(1);
    parentWidget()->close();
    text->show();
}

void FB::rebuildof16_2()
{
    pan *text = new pan(2);
    parentWidget()->close();
    text->show();
}

void FB::rebuildof16_3()
{
    pan *text = new pan(3);
    parentWidget()->close();
    text->show();
}

void FB::rebuildof9()
{
    panof9 *text = new panof9();
    parentWidget()->close();
    text->show();
}

void FB::rebuildof9_1()
{
    panof9 *text = new panof9(1);
    parentWidget()->close();
    text->show();
}

void FB::rebuildof9_2()
{
    panof9 *text = new panof9(2);
    parentWidget()->close();
    text->show();
}
void FB::rebuildof9_3()
{
    panof9 *text = new panof9(3);
    parentWidget()->close();
    text->show();
}
