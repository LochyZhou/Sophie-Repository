/*
Problem:136 - Ugly Numbers
Date:2013-10-18
Author: Sophie
Compiler:GNU GCC
Lang:C++
*/

//���ǰ�ֻ��������2��3��5�����������������Գ���ֻ�ܱ�2��3��5�������õ�1
//��ʹһ�����ֲ��ǳ��������ǻ�����Ҫ�������������ͳ�����������˸��㷨��ʱ��Ч�ʲ��Ǻܸߡ�
//����ֻ������������ڷǳ����ϻ�ʱ��
//����Ӧ������һ����������2��3��5�Ľ����1���⣩

#include <stdio.h>
void getNextMinUgly(int *uglyNum, int maxUgly, int &minNUgly, int count, int prime);
 int main()
 {
     int uglyNum[1500];
     uglyNum[0] = 1;
     int count = 1;
     int minNUgly = 2;
     int maxUgly = 1;

     while(count<1500)
     {
        getNextMinUgly(uglyNum,maxUgly,minNUgly,count,2);
        getNextMinUgly(uglyNum,maxUgly,minNUgly,count,3);
        getNextMinUgly(uglyNum,maxUgly,minNUgly,count,5);
        uglyNum[count++] = minNUgly;
        maxUgly = minNUgly;
        minNUgly = maxUgly*2;
     }
     printf("The 1500'th ugly number is %d.\n",uglyNum[1499]);
     return 0;
 }

void getNextMinUgly(int *uglyNum, int maxUgly, int &minNUgly, int count, int prime)
{
    int i,j;
    for(i = 0;i<count && uglyNum[i] < maxUgly/prime;i++)
        ;
    for(j = i-1;j<count;j++)
    {
        int temp = uglyNum[j]*prime;
        if(temp>maxUgly && temp<minNUgly)
        {
            minNUgly = temp;
            break;//�ҵ���һ���Ϳ����˳�
        }
    }
}



