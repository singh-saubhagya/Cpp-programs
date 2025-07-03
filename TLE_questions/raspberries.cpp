#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>arr;
    arr.resize(n);
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
        flag=true;
    }
    if(flag)
    {
        cout<<0<<endl;
        return;
    }
    if(k==2)
    {
        bool mark=false;
        for(int i=0;i<n;i++)
        {
            if((arr[i]&1)==0)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        cout<<0<<endl;
        else
        cout<<1<<endl;
    }
    else if (k==3)
    {
        int ans=3;

        for(int i=0;i<n;i++)
        {
            if(arr[i]%3==0)
            {
                ans=0;
                break;
            }
            ans=min(ans,3-arr[i]%3);
        }
        cout<<ans<<endl;
    }
    else if(k==4)
    {
        int ct=0;
        int ans=4;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%4==0)
            {
                ans=0;
                break;
            }
            if((arr[i]&1)==0)
            {
                ct++;
            }
            ans=min(ans,4-arr[i]%4);
        }
        if(ans==0)
        {
            cout<<0<<endl;
        }
        else 
        {
            if(ct>=2)
            cout<<0<<endl;
            else if(ct>=1)
            cout<<1<<endl;
            else
            cout<<min(ans,2)<<endl;
        }
    }
    else 
    {
        int ans=5;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%5==0)
            {
                ans=0;
                break;
            }
            ans=min(ans,5-arr[i]%5);
        }
        cout<<ans<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}