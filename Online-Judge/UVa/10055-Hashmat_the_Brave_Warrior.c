/*
Problem:10055 - Hashmat the Brave Warior
Date: 2013-10-15
Author:Sophie
Compiler:GNU GCC
Lang:C
*/

//abs的头文件是stdlib.h  函数原型：int abs(int)
#include <stdio.h>

int main()
{
    long long int a,b;
    while(scanf("%lld %lld",&a,&b) != EOF)
    {
        if(a>b)
            printf("%lld\n",a-b);
        else
            printf("%lld\n",b-a);
    }
    return 0;
}
