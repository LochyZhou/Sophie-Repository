/*
2013-10-15
Problem:10300 - Ecological Premium
Date: 2013-10-15
Author: Sophie
Compiler:GNU GCC
Lang:C
*/

#include <stdio.h>
int main()
{
    int caseN,farmerN;
    int land,animal,degree;
    int i,j;
    long long int total;
    while(scanf("%d",&caseN) != EOF)
    {
        for(i = 0;i<caseN;i++)
        {
            total = 0;
            scanf("%d",&farmerN);
            for(j = 0;j<farmerN;j++)
            {
                scanf("%d %d %d",&land,&animal,&degree);
                total += land * degree;
            }
            printf("%lld\n",total);
        }
    }

    return 0;
}
