/*
Problem:541 - Error Correction
Date:2013-10-24
Athour:Sophie
Compiler:GNU GCC
Lang:C
Time:0.022s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=482
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,sum;
    int **p;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) break;
        p = (int**)malloc(sizeof(int*)*n);
        for(i = 0;i<n;i++)
        {
            p[i] = (int*)malloc(sizeof(int)*n);
            for(j = 0;j<n;j++)
                scanf("%d",&p[i][j]);
        }
        int iflag = 0,jflag = 0; //to index how many lines or coloums has odd sum;
        int pi,qj; //(pi,qj) is the change bit
        for(i = 0;i<n;i++)
        {
            sum = 0;
            for(j = 0;j<n;j++)
            {
                sum += p[i][j];
            }
            if(sum%2!=0)
            {
                iflag++;
                if(iflag > 1)
                    break;
                pi = i+1;
            }
        }
        for(j = 0;j<n;j++)
        {
            sum = 0;
            for(i = 0;i<n;i++)
                sum += p[i][j];
            if(sum%2!=0)
            {
                jflag++;
                if(iflag > 1)
                    break;
                qj = j+1;
            }
        }
        if(iflag == 0&&jflag == 0)
            printf("OK\n");
        else if(iflag == 1&&jflag ==1)
            printf("Change bit (%d,%d)\n",pi,qj);
        else
            printf("Corrupt\n");
        //delete the pointer
        for(i = 0;i<n;i++)
            free(p[i]);
        free(p);
        p = NULL;
    }
    return 0;
}
