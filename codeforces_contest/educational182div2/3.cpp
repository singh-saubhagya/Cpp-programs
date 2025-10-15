#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli  dp[105][105];
vector<lli > a,b;
lli  n;
const lli mod = 998244353;
lli  rec(lli  i, lli  prev)
{
    if(i==n+1)
    {
        return 1 ;
    }
    if(dp[i][prev]!=-1)
    return dp[i][prev];

    // check 
    lli  check = 0; 
    if(prev==i-1)
    {
        check = 1 ;// we have to take the prev index and change 
    }
    lli  ans = 0 ; 
   
    if(check)
    {
        if(a[i]>=b[i-1] && b[i]>=a[i-1])
        {
           ans += rec(i+1,prev);
           ans=ans%mod;
        }
        if(b[i]>=b[i-1] && a[i]>=a[i-1])
        {
           ans+= rec(i+1,i); ans=ans%mod;
        }
    }
    else 
    {
        if(a[i]>=a[i-1] && b[i]>=b[i-1])
        {
           ans+= rec(i+1,prev); ans=ans%mod;
        }
        if(b[i]>=a[i-1] && a[i]>=b[i-1])
        {
           ans+= rec(i+1,i); ans=ans%mod;
        }
    }
    return dp[i][prev]=ans;
}
void solve()
{
    a.clear();
    b.clear();
    cin>>n;
    a.resize(n+2);
    b.resize(n+2);
    for(lli  i=1;i<=n;i++)
    cin>>a[i];
    for(lli  j=1;j<=n;j++)
    cin>>b[j];

    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;cin>>t;while(t--)solve();
}