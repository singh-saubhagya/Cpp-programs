#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr;
        arr.resize(n+1); 
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int ct=0;
        for(int i=0;i<=n-2;i++)
        {
        int j=i+1;
        if(!(arr[i]&1 ^ arr[j]&1))
        {
            ct++;
        }
        
        }cout<<ct<<endl;
    }
}