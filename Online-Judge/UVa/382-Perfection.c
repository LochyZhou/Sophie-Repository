/*
Problem: 382 - Perfection
Date:2013-10-21
Author:Sophie
Compile:GNU GCC
Lang:C
Time:
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=318
*/

#include <stdio.h>
int judge(int num);

int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)!= EOF)
    {
        if(!n) break;
        int style = judge(n);
        switch(style)
        {
            case 1:
                printf("%5d  PERFECT\n",n);
            break;
            case 2:
                printf("%5d  DEFICIENT\n",n);
            break;
            case 3:
                printf("%5d  ABUNDANT\n",n);
            break;
            default:
            ;
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
//1：表示perfect  2：表示 deficient 3：表示abundant
int judge(int num)
{
    //考虑1的情况
    if(num == 1)
        return 2;
    int i,j;
    int sum =1;
    for(i = 2;i*i<num;i++)
    {
        if(num%i == 0)
            sum += (i + num/i);
    }
    if(i*i == num)
        sum += i;
    if(sum == num) return 1;
    else if(sum < num) return 2;
    else return 3;
}







