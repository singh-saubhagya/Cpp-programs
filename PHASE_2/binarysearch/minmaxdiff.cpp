#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long
vector<lli> arr;
vector<lli> result;
bool check(int mid,int k)
{
    if(mid==0)
    {
        return  false;

    }
    int point=0;
    for(int i=1;i<arr.size();i++)
    {
        int diff=arr[i]-arr[i-1];
        if(diff>mid)
        {
            point =point+ceil(((double)diff)/mid)-1;
        }
    }
   
    if(point<=k)
    return true;
    else
    return false;
}
void solve()
 {
    lli n, k;
    cin>>n>>k;
    lli size,maxdiff=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        size=arr.size();
        if(size>=2)
        {
            int diff=arr[size-1]-arr[size-2];
            if(diff>maxdiff)
            {
                maxdiff=diff;
            }           
        }
    }
    int lo=0,hi=maxdiff;
    int ans;
    if(k==0)
    {
        result.push_back(maxdiff);
        return;
    }
    lli mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        
        if(check(mid,k)==true)
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }  
    result.push_back(ans);  

 }
 signed main()
 {
   int q;
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   cin>>q;
   cout<<endl;

   while(q--)
   {
    solve();
    arr.clear();
   }
   for(int i:result)
   {
    cout<<i<<endl;
   }

 }