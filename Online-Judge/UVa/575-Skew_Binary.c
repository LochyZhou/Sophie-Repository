/*
Problem: 575 - Skew Binary
Date:2013-10-21
Author:Sophie
Compile:GNU GCC
Lang:C
Time:0.022s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=516
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char p[50],ch;
    int len,i;
    int result;
    while((ch = getchar())!= EOF)
    {
        if(ch == '0') break;
        p[0] = ch;
        i = 1;
        while((ch = getchar()) != '\n')
        {
            p[i++] = ch;
        }
        //�ֶ�����ַ��γ��ַ�����ע���Լ���ӽ�����
        p[i] = '\0';
        len = strlen(p);
        result = 0;
        for(i = len; i>=0;i--)
        {
            //ע�����������ʱ�����ַ��������֣�����ʱ����ת��
            result += (p[len-i]-'0') * (pow(2,i)-1);
        }
        printf("%d\n",result);
    }
    return 0;
}
