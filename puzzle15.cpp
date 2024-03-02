#include "puzzle15.h"

puzzle15::puzzle15()
{
}

void puzzle15::mymove(){
    if(b[gettx()+1][getty()+1+1]==0)
    {
        swap(&b[gettx()+1][getty()+1],&b[gettx()+1][getty()+1+1]);move((setty(getty()+1),getty())*200,gettx()*200);
        emit enterEvent_1();
    }

    else if(b[gettx()+1][getty()+1-1]==0)
    {
        swap(&b[gettx()+1][getty()+1],&b[gettx()+1][getty()+1-1]);move((setty(getty()-1),getty())*200,gettx()*200);
        emit enterEvent_1();
    }
    else if(b[gettx()+1+1][getty()+1]==0)
    {
        swap(&b[gettx()+1][getty()+1],&b[gettx()+1+1][getty()+1]);move(getty()*200,(settx(gettx()+1),gettx())*200);
        emit enterEvent_1();
    }
    else if(b[gettx()+1-1][getty()+1]==0)
    {
        swap(&b[gettx()+1][getty()+1],&b[gettx()+1-1][getty()+1]);move(getty()*200,(settx(gettx()-1),gettx())*200);
        emit enterEvent_1();
    }
}
void puzzle15::enterEvent(QEvent *)
{
       mymove();
}




