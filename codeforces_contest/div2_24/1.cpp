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
    for(lli  i=1;i<=n;i++)
    cin>>arr[i];

    vector<lli > dp;
    dp.assign(n+2,-1);

    vector<lli > ps;
    ps.assign(n+2,0);
    for(lli  i=1;i<=n;i++)
    {
        ps[i]=arr[i]-1+ps[i-1];
    }
    lli  prev=0;
    for(lli  i=1;i<=n;i++)
    {
        lli  val1=arr[i];
        if(i+1<=n)
        {
            lli  h1=i;
            if(arr[i+1]>h1)
            {
                val1+=arr[i+1]-i;
            }
            if(i+2<=n)
            {
                val1+=ps[n]-ps[i+1];
            }
        }
       
        dp[i]=val1+prev;
        if(i==1)
        {
            prev=arr[i];
        }
        else 
        {
            prev+=max(0LL,arr[i]-1);
        }
    }
    lli  ans=dp[1];
    for(lli  i=1;i<=n;i++)
    {ans=min(ans,dp[i]);}
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;
  cin>>t;
  while(t--)
  solve();
}