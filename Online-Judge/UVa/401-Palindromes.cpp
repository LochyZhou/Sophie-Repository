/*
Problem: 401 - Palindromes
Date:2013-10-17
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>
#include <string.h>

const int MAX = 30;
int is_mirror(char ch1,char ch2);

int main()
{
    int isPalindrome,isMirror;
    char p[MAX];
    int len;
    int flag1,flag2;

    while(scanf("%s",p) !=EOF )
    {
        len = strlen(p);
        isPalindrome = 1;
        isMirror = 1;
        flag1 = flag2 = 0;
        printf("%s -- ",p);
        for(int i = 0;i<len/2;i++)
        {
            //注意0和o是等价的
            if((p[i] == '0'&&p[len-i-1]=='O')||(p[i]=='O'&&p[len-i-1]=='0'))
                continue;
            if(!flag1 && p[i] != p[len-i-1])
            {
                flag1 = 1;
                isPalindrome = 0;
            }

            if(!flag2 && !is_mirror(p[i],p[len-i-1]))
            {
                flag2 = 1;
                isMirror = 0;
            }
            if(flag1&&flag2)
                break;
        }
        //判断镜像时千万别忘了中间那个
        if(isMirror && len%2!=0)
        {
            if(!is_mirror(p[(len+1)/2-1],p[(len+1)/2-1]))
               isMirror = 0;
        }
        //输出
        if(!isPalindrome&&!isMirror)
            printf("is not a palindrome.\n\n");
        if(isPalindrome&&!isMirror)
            printf("is a regular palindrome.\n\n");
        if(!isPalindrome&&isMirror)
            printf("is a mirrored string.\n\n");
        if(isPalindrome&&isMirror)
            printf("is a mirrored palindrome.\n\n");
    }
    return 0;
}

//是返回1，否则返回0
int is_mirror(char ch1,char ch2)
{
    char *character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    char *reverse =   "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    int len = strlen(character);
    int index;
    for(index = 0;index<len;index++)
    {
        if(character[index] == ch1)
            break;
    }
    if(index != len && ch2 != ' ' && reverse[index] == ch2)
        return 1;
    else
        return 0;
}

//注意：判断镜像时千万别忘了中间那个，因为这个原因WA了很多次














