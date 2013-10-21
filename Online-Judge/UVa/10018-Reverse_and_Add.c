/*
Problem:UVa 10018 - Reverse and Add
Date:2013-10-19
Author:Sohpie
Compiler: GNU GCC
Lang: C
Time:
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=959
*/

#include <stdio.h>
#include <string.h>
int is_palindrome(unsigned int num);
unsigned int iteration(unsigned int num);

int main()
{
    int caseN,addcount;
    unsigned int value,strResult;
    int i;
    scanf("%d",&caseN);
    for(i = 0;i<caseN;i++)
    {
        addcount = 0;
        scanf("%u",&value);
        while(1)
        {
            strResult = iteration(value) + value;
            addcount++;
            if(is_palindrome(strResult))
                break;
            else
                value = strResult;
        }
        printf("%d %u\n",addcount,strResult);
    }

    return 0;
}

int is_palindrome(unsigned int num)
{
    char p[10];
    sprintf(p,"%u",num);
    int i,len = strlen(p);
    for(i = 0;i<len/2;i++)
        if(p[i] != p[len-i-1])
            return 0;
    return 1;
}

unsigned int iteration(unsigned int num)
{
    char p[10],ch;
    int i,len;
    unsigned int result;
    sprintf(p,"%u",num);
    len = strlen(p);

    for(i = 0;i<len/2;i++)
    {
        ch = p[i];
        p[i] = p[len- i-1];
        p[len-i-1] = ch;
    }
    sscanf(p,"%u",&result);
    return result;
}






