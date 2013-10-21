/*
Problem:UVa 369 - Combinations
Date:2013-10-20
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=305
*/


#include <stdio.h>
#include <stdlib.h>
double factorial(double n);
int main()
{
    double n,m;
    long long result;
    while(scanf("%lf %lf",&n,&m)!= EOF)
    {
        if(!n&&!m) break;
        result = (long long)(factorial(n)/(factorial(n-m)*factorial(m))+0.5);
        printf("%d things taken %d at a time is %ld exactly.\n",(int)n,(int)m,result);
    }


    return 0;
}

double factorial(double n)
{
    int i;
    double result = 1;
    for(i = n;i>=1;i-- )
        result *= i;
    return result;
}
