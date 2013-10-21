/*
Problem: 151 - Power Crisis
Date:2013-10-21
Author:Sophie
Compile:GNU GCC
Lang:C
Time:0.015s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=87
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *flag,yes;
    int n,m,i;
    int count,lastRegion;
    while(scanf("%d",&n)!= EOF)
    {
        if(!n) break;
        flag = (int*)malloc(sizeof(int)*n);
        //步长m
        for(m = 1;;m++)
        {
            memset(flag,0,sizeof(int)*n);
            lastRegion = 0;
            count = 1;
            yes = 0;
            flag[lastRegion] = 1;
            while(1)
            {
                //注意以下这个过程，不是找到那个点往下搜索未停过电的区域
                for(i = 0;i<m;i++)
                {
                    while(flag[(++lastRegion)%n]);
                }
                flag[lastRegion%n] = 1;
                lastRegion = lastRegion%n;
                count++;
                //特定的区域13，不是n成为最后一个区域
                if(flag[12] == 1 && count < n)
                    break;
                if(flag[12] == 1 && count == n)
                {
                    yes = 1;
                    break;
                }
            }
            if(yes == 1)
                break;
        }
        printf("%d\n",m);
    }
    return 0;
}









