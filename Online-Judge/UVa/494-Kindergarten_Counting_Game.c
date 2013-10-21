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
    //scanf����˵��س�
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

//��Ҫ�Կո���Ϊ����֮��ķָ���������һ���������Ĵ���eg: I am a student,a boy.also.
//��ͳ��ʱ���ܻ�©�����һ�����ʣ���Ȼ���һ��Ҳ��һ���ǵ���




