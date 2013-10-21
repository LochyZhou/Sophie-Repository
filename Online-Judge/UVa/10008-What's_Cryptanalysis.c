/*
Problem:UVa 10008 - What's Cryptanalysis?
Date:2013-10-20
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.015
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
*/


#include <stdio.h>
#include <string.h>

void sort(char *letter, int *count);
int main()
{
    int nLine,i;
    char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count[26];
    int ch;
    memset(count,0,sizeof(int)*26);
    while(scanf("%d",&nLine)!=EOF)
    {
        getchar();//去除输入行数后的回车
        for(i = 0;i<nLine;i++)
        {
            while((ch = getchar())!='\n')
            {
                if(ch>='a' && ch<='z')
                    count[ch-'a']++;
                if(ch>='A' && ch<='Z')
                    count[ch-'A']++;
            }
        }
        sort(letter,count);
        for(i = 0;i<26;i++)
        {
            if(count[i] == 0) break;
            printf("%c %d\n",letter[i],count[i]);
        }
    }
    return 0;
}

//冒泡排序
void sort(char *letter, int *count)
{
    int i,j;
    for(i = 0;i<26;i++)
        for(j = 25;j>i;j--)
        {
            //小的
            if(count[j]>count[j-1])
            {
                int temp = count[j-1];
                count[j-1] = count[j];
                count[j] = temp;
                char ch = letter[j-1];
                letter[j-1] = letter[j];
                letter[j] = ch;
            }
            if(count[j] == count[j-1] && letter[j]<letter[j-1])
            {
                char ch = letter[j-1];
                letter[j-1] = letter[j];
                letter[j] = ch;
            }
        }
}







