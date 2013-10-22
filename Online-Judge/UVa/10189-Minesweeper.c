/*
Problem: 10189 - Minesweeper
Date:2013-10-22
Author:Sophie
Compiler:GNU GCC
Lang:C
Time:0.019s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1130
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a, int b)
{
    if(a>=b) return a;
    else return b;
}

int min(int a, int b)
{
    if(a<=b) return a;
    else return b;
}

int main()
{
    int n,m,i,j,p,q;
    int **arr;
    int ch;
    int fieldIndex = 0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(!n&&!m) break;
        fieldIndex++;
        arr = (int**)malloc(sizeof(int*)*n);
        if(fieldIndex>1)
            printf("\n");
        for(i = 0;i<n;i++)
        {
            arr[i] = (int*)malloc(sizeof(int)*m);
            memset(arr[i],0,sizeof(int)*m);
        }

        //input
        ch = getchar();
        for(i = 0;i<n;i++)
        {
            for(j = 0;j<m;j++)
            {
                if((ch = getchar()) == '*')
                {
                    //deal with the surrounds of mine
                    arr[i][j] = -1;
                    for(p = max(i-1,0);p<=min(i+1,n-1);p++)
                        for(q = max(j-1,0);q<=min(j+1,m-1);q++)
                        {
                            if(arr[p][q]!= -1)
                                arr[p][q]++;
                        }
                }
            }
            ch = getchar();
        }
        //output
        printf("Field #%d:\n",fieldIndex);
        for(i = 0;i<n;i++)
        {
            for(j = 0;j<m;j++)
            {
                if(arr[i][j] == -1)
                    printf("*");
                else
                    printf("%d",arr[i][j]);
            }
            printf("\n");
        }
        //release the n*m array
        for(i = 0;i<n;i++)
            free(arr[i]);
        free(arr);
        arr = NULL;

    }
    return 0;
}

