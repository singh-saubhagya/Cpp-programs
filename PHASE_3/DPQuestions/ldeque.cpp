#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
lli  n;
lli  dp[3003][3003][3];
#define inf 1e18
vector<lli >arr;
lli  rec(lli  l, lli  r, lli  turn)
{
   if(l>r)
   {
    return 0;// base case 
   }
   if(dp[l][r][turn]!=-1)
   return dp[l][r][turn];

   lli  ans;
   if(turn)
   {
    ans=-inf;
    ans=max(ans,arr[l]+rec(l+1,r,0));
    ans=max(ans,arr[r]+rec(l,r-1,0));
   }
   else 
   {
    ans=inf;
    ans=min(ans,rec(l+1,r,1)-arr[l]);
    ans=min(ans,rec(l,r-1,1)-arr[r]);
   }
//    cout<<l<<" "<<r<<" "<<turn<<" "<<ans<<endl;
   return dp[l][r][turn]=ans;
}
signed main(){
    
    cin>>n;
    arr.resize(n+1);
    for(lli  i=1;i<=n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n,1);
}