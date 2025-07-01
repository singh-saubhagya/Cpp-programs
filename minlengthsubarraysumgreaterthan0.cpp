/*
from each index i find j , such that sum of i to j(subarray from index i to j ) is > 0.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    vector<int> arr,ps;
    arr.resize(n+1);
    ps.assign(n+1,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i)
        {
            ps[i]=ps[i-1]+arr[i];
        }
        else 
        {
             ps[0]=arr[0];
        }
    }
   
    vector<int> ans;
    ans.resize(n+1);

    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.empty()==false && ps[s.top()]<=ps[i])
        {
            s.pop();
        }
        if(s.empty()==false)
        {
            ans[i]=s.top();
        }
        else 
        {
            ans[i]=-1;
        }
        s.push(i);
    }
    
    int y=0;
    for(int i=0;i<n;i++)
    {
        if(ps[i]>0)
        {
            y=i+1;
            break;
        }
    }
    cout<<y<<" ";
    for(int i=1;i<n;i++)
    {   
        int x=ans[i-1];
        if(x==-1)
        {
            if(arr[i]>0)
            cout<<1<<" ";
            else 
            cout<<0<<" ";
        }
        else 
        {
            cout<<x-(i-1)<<" ";
        }
    }
}