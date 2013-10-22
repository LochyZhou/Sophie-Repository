/*
Problem: 264 - Count on Cantor
Date:2013-10-22
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.019s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=200
*/

#include <stdio.h>

int main()
{
    int m,i;

    while(scanf("%d",&m)!= EOF)
    {
        //calculate which line is the Mth number in
        for(i = 0;(i+1)*i/2<m;i++)
            ;
        //The Nth iterm from the bottom in line i;
        int n = (i+1)*i/2 - m +1;
        if(i%2 == 0)
            printf("TERM %d IS %d/%d\n",m,i-n+1,n);
        else
            printf("TERM %d IS %d/%d\n",m,n,i-n+1);
    }

    return 0;
}
