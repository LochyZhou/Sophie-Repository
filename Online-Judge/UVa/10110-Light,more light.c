/*
Problem: 10110 - Light, more light
Date:2013-10-24
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.023s
Problem:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1051
*/

#include <stdio.h>
#include <math.h>
int isSquareNum(unsigned int num);
int main()
{
    unsigned int n;
    while(scanf("%u",&n)!=EOF)
    {
        if(!n) break;
        if(isSquareNum(n) == 0)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;

}

//just need to judge that is it a square number
int isSquareNum(unsigned int num)
{
    double sq = sqrt(num);
    if((sq - floor(sq)) < 0.000001)
        return 1;
    else
        return 0;
}
