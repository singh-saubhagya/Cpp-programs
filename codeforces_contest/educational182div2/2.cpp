#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli  n;
    cin>>n;
    vector<lli > arr;
    arr.resize(n+2);
    for(lli  i=0;i<n;i++)
    cin>>arr[i];
    lli  ct=0;
    lli  sum=0;
    for(lli  i=0;i<n;i++)
    {
        if(arr[i]==0)
        ct++;
        sum+=arr[i];
    }
    if(ct==0)
    {
        int pt1=-1;
        int pt2=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=(i+1))
            {
                pt1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=(i+1))
            {
                pt2=i;
                break;
            }
        }
        if(pt1!=-1)
        cout<<pt2-pt1+1<<endl;
        else 
        cout<<0<<endl;
    }
    else if(ct==1)
    {
        lli  left=n*(n+1);
        left=left/2;
        left=left-sum;
        int pt1=-1;
        int pt2=-1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            arr[i]=left;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=(i+1))
            {
                pt1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=(i+1))
            {
                pt2=i;
                break;
            }
        }
        if(pt1!=-1)
        {
            cout<<pt2-pt1+1<<endl;
        }
        else 
        {
            cout<<0<<endl;
        }
    }
    else 
    {
        int pt1=-1;
        int pt2=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=(i+1) || arr[i]==0)
            {
                pt1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=(i+1) || arr[i]==0)
            {
                pt2=i;
                break;
            }
        }
       
        cout<<pt2-pt1+1<<endl;
    }
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;cin>>t;while(t--)solve();
}