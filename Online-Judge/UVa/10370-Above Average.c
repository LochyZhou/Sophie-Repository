/*
Problem: 10370 - Above Average
Date:2013-10-23
Author: Sophie
Copiler:GNU GCC
Lang:C
Time:0.015s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1311
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c,n,i,j;
    int *p;
    scanf("%d",&c);
    for(i = 0;i<c;i++)
    {
        float ave = 0;
        scanf("%d",&n);
        p = (int*)malloc(sizeof(int)*n);
        for(j = 0;j<n;j++)
        {
            scanf("%d",&p[j]);
            ave += p[j];
        }
        ave /= n;
        int count =0;
        for(j = 0;j<n;j++)
        {
            if(p[j] > ave) count++;
        }
        printf("%.3f%%\n",(float)count/(float)n*100);
        free(p);
    }
    return 0;
}
