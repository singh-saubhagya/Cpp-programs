#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t' 
int n,w;vector<int> arr,scr;
int nn;
int dp[110][110][110];
const int inf = 1e9 ;
int rec(int i,int rem,int no)
{
    
    if(i==n )
    {
        if(no==nn && (w-rem)%no==0)
        return 0; 
        return -inf;
    }
    
    if(dp[i][rem][no]!=-1)
    return dp[i][rem][no];

    int ans=rec(i+1,rem,no);
    if(arr[i]<=rem)
    {
        ans=max(ans,scr[i]+rec(i+1,rem-arr[i],no+1));
    }
    return dp[i][rem][no]=ans;
}
void solve()
{
   
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    arr.resize(n+2);
    scr.resize(n+2);
    for(int i=0;i<n;i++)
    cin>>scr[i];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=1;i<=n;i++)
    {
        memset(dp,-1,sizeof(dp));
        nn=i;
        cout<<i<<" "<<rec(0,w,0)<<endl;
    }

    
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}