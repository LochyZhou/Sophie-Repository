/*
Problem: 160 - Factors and Factorials
Date:2013-10-23
Author: Sophie
Copiler:GNU GCC
Lang:C++
Time:0.012s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=96
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int generateNextPrime(int lastPrime);
int main()
{
    vector<int> record;
    int index; //index the last position of record which stores number;from -1 means no data in vector;
    int *data;
    int countOne;
    int N;
    int lastPrime;
    while(scanf("%d",&N)!= EOF)
    {
        if(!N) break;
        lastPrime = 2;
        countOne = N-1;
        record.clear();
        index = -1;
        data = (int*)malloc(sizeof(int)*(N-1));
        for(int i = 0;i<=N-2;i++)
            data[i] = i+2;
        //the date is divied by a prime from N~2 for every round until the N numbers are all divided to 1;
        while(countOne > 0)
        {
            record.push_back(0);
            index++;
            for(int i = 0;i<=N-2;i++)
            {
                while(data[i]%lastPrime == 0)
                {
                    data[i] /= lastPrime;
                    if(data[i] == 1) countOne--;
                    record[index]++;
                }
            }
            lastPrime = generateNextPrime(lastPrime);
        }
        printf("%3d! =",N);
        for(int i = 0;i<record.size();i++)
        {
            if(i && i%15 == 0)
                printf("\n      ");
            printf("%3d",record[i]);
        }
        printf("\n");
    }
    return 0;
}

int generateNextPrime(int lastPrime)
{
    int i,j;
    for(i = lastPrime+1;;i++)
    {
        for(j = 2; j*j<=i;j++)
            if(i%j == 0) break;
        if(j*j>i) return i;
    }
}
