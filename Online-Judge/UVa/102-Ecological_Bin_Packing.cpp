/*
Problem:102 - Ecological Bin Packing
Date:2013-10-18
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>

int main()
{
    int num[9];
    int minCount,minIndex;
    int numIndex[18] = {0,5,7,0,4,8,2,3,7,2,4,6,1,3,8,1,5,6};
    char style[6][3] = {'B','C','G','B','G','C','C','B','G','C','G','B','G','B','C','G','C','B'};

    while( scanf("%d",&num[0]) != EOF )
    {
        minCount = num[0];
        minIndex = 0;
        for(int i = 1;i<9;i++)
        {
             scanf("%d",&num[i]);
             minCount += num[i];
        }
        int total = minCount;
        int addTemp;
        //BCG--0 BGC--1 CBG--2 CGB--3 GBC--4 GCB--5
        for(int i = 0;i<6;i++)
        {
            addTemp = total - num[numIndex[i*3]] - num[numIndex[i*3+1]] - num[numIndex[i*3+2]];
            if(addTemp < minCount)
            {
                minCount = addTemp;
                minIndex = i;
            }
        }
        printf("%c%c%c %d\n",style[minIndex][0],style[minIndex][1],style[minIndex][2],minCount);

    }
    return 0;
}




















