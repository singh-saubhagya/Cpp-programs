#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define  endl '\n'
#define  tab '\t'

lli ct=0;
void rec(lli t1)
{
    if(t1==0)
    return;
    if(t1==1)
    {
        ct++;
        return ;
    }
    // we have x discs in t1 and 0 in both t2 and t3 .
    // first fn
    
    rec(t1-1);    // fn1; // we will aim to move x-1 discs to t2 and 1 discs to t3
    ct++; // moving 1 disc to t3;


    rec(t1-1);// now moving t1-1 disc to t3
   

}

int main()
{
    lli x;
    cin>>x;
    rec(x);
    cout<<ct;
}