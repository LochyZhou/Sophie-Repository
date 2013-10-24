/*
Problem: 10107 - What is the Median?
Date:2013-10-24
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.046s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1048
*/
#include <stdio.h>
#include <string.h>
void insert(int *s, int len, int num);
int getMedian(int *s, int len);
int main()
{
    int s[10000];
    int len = 0;
    int num;
    memset(s,0,sizeof(int)*10000);
    while(scanf("%d",&num)!=EOF)
    {
        insert(s,len,num);
        len++;
        printf("%d\n",getMedian(s,len));
    }
    return 0;
}

//insertion sorting
//pay attention:len is the lenght of s before num inserted.
void insert(int *s, int len, int num)
{
    int i,j;
    for(i = 0;i<len;i++)
        if(s[i] > num)
            break;
    for(j = len-1;j>=i;j--)
        s[j+1] = s[j];
    s[i] = num;
}
//pay attention: the array is sequential
int getMedian(int *s, int len)
{
    if(len%2 == 0)
        return (s[len/2-1]+s[len/2])/2;
    else return s[len/2];
}
