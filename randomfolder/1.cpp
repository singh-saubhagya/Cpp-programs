#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli  dp[1000006+2][20];
lli  n;
const lli mod = 1e9+7;
lli  rec(lli  level,lli  mask)
{
    if(mask==4)
    {
        return 0;
    }
    if(level==0)
    return 1;

    if(dp[level][mask]!=-1)
    { return dp[level][mask];}

    lli  ans=0;
    lli  a=(mask<<1|1)&15;
    lli  b=(mask<<1)&15;
    ans=(rec(level-1,a)%mod+rec(level-1,b)%mod)%mod;
    
    return dp[level][mask]=ans;

}
void solve()
{

    cin>>n;

    cout<<rec(n,0)<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  memset(dp,-1,sizeof(dp));
  lli  t;cin>>t;while(t--)solve();
}