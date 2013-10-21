/*
problem:UVa 10038 - Jolly Jumpers
Date:2013-10-19
Author:Sohpie
Compiler: GNU GCC
Lang: C
Time: 0.022s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,n;
    int *value; //n个
    int *check; //n-1个
    while(scanf("%d",&n) != EOF)
    {
        value = (int*)malloc(sizeof(int)*n);
        check = (int*)malloc(sizeof(int)*n-1);
        memset(check,0,sizeof(int)*(n-1));

        scanf("%d",&value[0]);
        for(i = 1;i<n;i++)
        {
            scanf("%d",&value[i]);
            int dif = abs(value[i] - value[i-1]);  //差的绝对值
            if(dif > 0 && dif < n)
                check[dif-1] = 1;
        }
        if(n == 1)
        {
            printf("Jolly\n");
            continue;
        }
        int flag = 1;
        for(i = 0;i<n-1;i++)
        {
            if(check[i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
