/*
Problem:694 - The Collatz Sequence
Date:2013-10-17
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>

int main()
{
    int num,limit;
    int caseIndex = 0;
    int term;
    while(scanf("%d %d",&num,&limit) == 2)
    {
        if(num<0 && limit<0)
            break;
        term = 0;
        caseIndex++;
        int temp = num;
        while(1)
        {
            if(temp>limit || temp<0)
                break;
            term++; //1Ò²ËãÒ»Ïî
            if(temp == 1)
                break;
            if(temp%2==0)
                temp = temp/2;
            else
                temp = temp*3+1;
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",caseIndex,num,limit,term);
    }
    return 0;
}















