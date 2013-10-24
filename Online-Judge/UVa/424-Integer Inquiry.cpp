/*
Problem:424 - Interger Inquiry
Date:2013-10-23
Author:Sophie
Compile:GNU GCC
Lang:C++
Time:0.019s
Problem Address:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=365
*/

#include <iostream>
#include <string.h>
using namespace std;

const int lenMax = 1000;
struct bign
{
    int s[lenMax];
    int len;
    bign()
    {
        memset(s,0,sizeof(s));
        len = 1;
    }
    //overloaded operator =
    bign operator = (const char* num)
    {
        len = strlen(num);
        for(int i = 0;i<len;i++)
            s[i] = num[len-i-1] - '0';
        return *this;
    }
    //support for initializing
    bign(const char* num)
    {
        *this = num;
    }
    //overloaded operator +
    bign operator + (const bign& b)const
    {
        bign c;
        c.len = 0;
        for(int i = 0,g=0; g||i<max(len,b.len); i++)
        {
            int x = g;
            if(i<len) x += s[i];
            if(i<b.len) x += b.s[i];
            c.s[c.len++] = x%10;
            g = x/10;
        }
        return c;
    }
    //overloaded operator +=
    bign operator += (const bign& b)
    {
        *this  = *this + b;
        return *this;
    }
    string str() const
    {
        string res = "";
        for(int i = 0;i<len;i++)
        {
            res = (char)(s[i] + '0') + res;
        }
        if(res == "")
            res = "0";
        return res;
    }
};
//redefine input / output stream
istream& operator >> (istream &in, bign& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign& x)
{
    out << x.str();
    return out;
}

int main()
{
    bign total = "0";
    bign a;
    while(cin>>a)
    {
        if(a.str() == "0") break;
        total += a;
    }
    cout << total <<endl;
    return 0;
}
