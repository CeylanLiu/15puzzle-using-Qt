 //9puzzle的块
#ifndef PUZZLE9_H
#define PUZZLE9_H

#include <block.h>
class puzzle9 : public block
{
public:
    puzzle9();
    static int c[5][5];
    virtual void enterEvent(QEvent *) override;
    virtual void mymove() override;
    //以下的几个函数用于判断是否可以复原
    int getInvCount(int arr[])
    {
        int inv_count = 0;
        for (int i = 0; i < 9 - 1; i++)
            for (int j = i+1; j < 9; j++)
                if (arr[j] && arr[i] &&  arr[i] > arr[j])
                    inv_count++;
        return inv_count;
    }
    // 如果可解，返回值为真
    bool isSolvable(int puzzle[3][3])
    {
        int invCount = getInvCount((int *)puzzle);
        return (invCount%2 == 0);
    }
};

#endif // PUZZLE9_H
