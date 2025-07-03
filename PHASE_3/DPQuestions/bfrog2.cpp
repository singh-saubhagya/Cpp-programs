#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define inf 1e9
int n,k;
vector<int> arr;
int dp[100002];
int rec(int i)
{
    if(i==0)// valid state so returning 0
    return 0;
    int ans=inf;

    if(dp[i]!=-1)
    return dp[i];
    for(int j=1;j<=k;j++)
    {
        int st=i-j;
       
        if(st>=0)
        {
            ans=min(ans,abs(arr[st]-arr[i])+rec(st));
        }
        else
        break;
       
    }
    return dp[i]=ans;

}
signed main()
{   
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1);
}