#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;arr.push_back(x);
    }
    map<int,int> a,b;
    int ct=0;

    for(int i=n-1;i>=0;i--)
    {
        for(auto x:b)
        {
           int temp=x.first&arr[i];
           // if temp is new element therfore added in the newsubarray with freq x.second.
           // if temp is old element i.e already present in the subarray a, then 
           a[temp]+=x.second;
        }
        a[arr[i]]++;
        for(auto x:a)
        {
            if(x.first==k)

            {
                ct+=x.second;
            }
        }
        b=a;
        a.clear();
    }
    cout<<ct<<endl;
}