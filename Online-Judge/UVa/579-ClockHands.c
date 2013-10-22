/*
Problem: 579 - ClockHands
Date:2013-10-22
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.042s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=520
*/

#include <stdio.h>
#include <math.h>

#define HOUR_PERDEG  30
#define MINIT_PERDEG 6
#define PERHOUR_PERMINIT 0.5
int main()
{
    int h,m;
    float degree;
    while(scanf("%d:%d",&h,&m) != EOF)
    {
        if(!h&&!m) break;
        degree = HOUR_PERDEG*h + PERHOUR_PERMINIT * m - MINIT_PERDEG *m;
        if(degree < 0)
            degree = degree*(-1.0);
        if(degree >= 180)
            degree = 360 - degree;
        printf("%.3f\n",degree);
    }
    return 0;
}
