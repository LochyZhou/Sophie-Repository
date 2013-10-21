/*
Problem:UVa 10035 - Primary Arithmetic
Date:2013-10-19
Author:Sohpie
Compiler: GNU GCC
Lang: C
Time: 0.029s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976
*/

#include <stdio.h>
#include <string.h>

int min(int a,int b)
{
    if(a<=b) return a;
    else return b;
}
int main()
{
    int numA,numB;
    char chA[10],chB[10];
    int count;

    while(scanf("%d %d",&numA,&numB) == 2)
    {
        if(!numA&&!numB) break;
        count = 0;
        sprintf(chA,"%d",numA);
        sprintf(chB,"%d",numB);

        int lenA = strlen(chA);
        int lenB = strlen(chB);
        int i,carry = 0;
        int a = lenA-1,b = lenB-1;
        for(i = 0; carry || i<min(lenA,lenB);i++)
        {
            int add = carry;
            if(a>=0) add += chA[a--] - '0';
            if(b>=0) add += chB[b--] - '0';
            if(add > 9)
            {
                carry = 1;
                count++;
            }
            else
                carry = 0;
        }
        if(count == 0)
            printf("No carry operation.\n");
        else if(count == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",count);
    }
    return 0;
}
