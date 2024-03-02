#include "puzzle9.h"

puzzle9::puzzle9()
{

}
void puzzle9::mymove(){
    if(c[gettx()+1][getty()+1+1]==0)
    {
        swap(&c[gettx()+1][getty()+1],&c[gettx()+1][getty()+1+1]);move((setty(getty()+1),getty())*200,gettx()*200);
        emit enterEvent_2();
    }

    else if(c[gettx()+1][getty()+1-1]==0)
    {
        swap(&c[gettx()+1][getty()+1],&c[gettx()+1][getty()+1-1]);move((setty(getty()-1),getty())*200,gettx()*200);
        emit enterEvent_2();
    }
    else if(c[gettx()+1+1][getty()+1]==0)
    {
        swap(&c[gettx()+1][getty()+1],&c[gettx()+1+1][getty()+1]);move(getty()*200,(settx(gettx()+1),gettx())*200);
        emit enterEvent_2();
    }
    else if(c[gettx()+1-1][getty()+1]==0)
    {
        swap(&c[gettx()+1][getty()+1],&c[gettx()+1-1][getty()+1]);move(getty()*200,(settx(gettx()-1),gettx())*200);
        emit enterEvent_2();
    }
}
void puzzle9::enterEvent(QEvent *){
    mymove();
}



