/*
Problem:UVa 113 - Power of Cryptography
Date:2013-10-20
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.019
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=49
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double n,p;
    while(scanf("%lf %lf",&n,&p) != EOF)
    {
        int result = (int)(pow(p,1/n)+0.5);
        printf("%d\n",result);
    }
    return 0;
}
