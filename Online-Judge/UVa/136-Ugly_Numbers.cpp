/*
Problem:136 - Ugly Numbers
Date:2013-10-18
Author: Sophie
Compiler:GNU GCC
Lang:C++
*/

//我们把只包含因子2、3和5的数称作丑数，所以丑数只能被2、3、5整除最后得到1
//即使一个数字不是丑数，我们还是需要对它做求余数和除法操作。因此该算法的时间效率不是很高。
//我们只计算丑数，不在非丑数上花时间
//丑数应该是另一个丑数乘以2、3、5的结果（1除外）

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
            break;//找到第一个就可以退出
        }
    }
}



