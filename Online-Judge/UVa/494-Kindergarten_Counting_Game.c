/*
Problem: 494 - Kindergarten Counting Game
Date: 2013-10-16
Author:Sophie
Compiler:GNU GCC
Lang:C
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int ch;
    int count = 0;
    int flag = 0;
    //scanf会过滤掉回车
    while((ch = getchar()) != EOF)
    {
        if(ch == ' ')
        {
            if(flag) count++;
            flag = 0;
        }
        else if(ch == '\n')
        {
            if(flag) count++;
            printf("%d\n",count);
            count = 0;
            flag = 0;
        }
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            flag = 1;
        else
        {
            if(flag)
            {
                count ++;
                flag = 0;
            }
        }
    }
    return 0;
}

//不要以空格作为单词之间的分隔符，这是一个很致命的错误eg: I am a student,a boy.also.
//在统计时可能会漏掉最后一个单词，当然最后一个也不一定是单词




