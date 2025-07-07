#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n,m;
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>m;
    int ct=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==m)
        {
            ct++;
        }
    }
    cout<<ct<<endl;
    }
   
}