/*
Problem: 484 - The Dapertment of Reduncancy Department
Date:2013-10-16
Author:Sophie
Compiler:GNU GCC
Lang:C++
*/

#include <stdio.h>
#include <vector>
using namespace std;

int is_exist(vector<int>buffer, int num);
int main()
{
    vector <int> arr;
    vector <int> buffer;
    vector <int> count;
    int a;
    while(scanf("%d",&a) != EOF)
    {
        arr.push_back(a);
    }
    for(int i = 0;i<arr.size();i++)
    {
        int temp = is_exist(buffer,arr[i]);
        if(temp == -1)
        {
            buffer.push_back(arr[i]);
            count.push_back(1);
        }
        else
        {
            count[temp]++;
        }
    }
    for(int i = 0;i<buffer.size();i++)
    {
        printf("%d %d\n",buffer[i],count[i]);
    }
    return 0;
}

 int is_exist(vector<int>buffer, int num)
 {
     for(int i = 0;i<buffer.size();i++)
     {
         if(num == buffer[i])
            return i;
     }
     return -1;
 }
