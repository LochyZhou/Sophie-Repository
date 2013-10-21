/*
Problem:490 - Rotating Sentences
Date:2013-10-16
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>
#include <string.h>
const int maxL = 100;
const int maxC = 100;
int main()
{
    char words[maxL][maxC];
    int len[maxL];
    memset(len,0,sizeof(int)*maxL);
    //输入
    int i = 0,j = 0;
    int ch;
    int maxLen = 0;
    while((ch = getchar()) != EOF)
    {
        //判断是不是空行
        if(ch!='\n')
        {
            j = 0;
            while(1)
            {
                words[i][j] = ch;
                j++;
                ch = getchar();
                if(ch == '\n') break;
            }
            len[i] = j;
            if(len[i]>maxLen)
                maxLen = len[i];
        }
        else
            len[i] = 0;
        i++;
        //去掉上一行留下的回车
    }
    for(int p = 0; p<maxLen; p++)
    {
        for(int q = i-1;q>=0;q--)
        {
            if(len[q]>p)
                printf("%c",words[q][p]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}




















