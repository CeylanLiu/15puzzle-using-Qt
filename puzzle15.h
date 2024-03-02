//15puzzle的块
#ifndef PUZZLE15_H
#define PUZZLE15_H

#include<block.h>

class pan;

class puzzle15 : public block
{
public:
    puzzle15();
    static int b[6][6];
    virtual void mymove() override;
    virtual void enterEvent(QEvent *) override;
};

#endif // PUZZLE15_H
