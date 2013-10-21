/*
Problem:458 - The Decoder
Date:2013-10-18
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
char replace(char* p,char ch);

int main()
{
    char *p = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    vector <char> str;
    char ch;
    while((ch = getchar()) != EOF)
    {
        str.clear();
        str.push_back(ch);
        while((ch = getchar())!='\n')
            str.push_back(ch);
        for(int i = 0;i<str.size();i++)
        {
            printf("%c",replace(p,str[i]));
        }
        printf("\n");
    }
    return 0;
}


char replace(char* p,char ch)
{
    for(int i = 0;i<strlen(p);i++)
    {
        if(p[i] == ch)
        {
            if(i-7>=0)
                return p[i-7];
            else
                return p[i-7+95];
        }

    }
}















