#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli a,b;
lli n;
vector<lli> arr;
lli dp[100005+2][3][3];
const lli mod = 676767677;
lli rec(lli i,lli dn,lli  prev)
{
    
    if(i==n)
    {
        return 1; 
    }
    if(dp[i][dn][prev]!=-1)
    return dp[i][dn][prev];

    lli  ans=0;
    lli  ct=1;
    lli  val1,val2;
    if(dn==1)
    {
         val1=a;
       
        if(prev==1)
        {
            val2=b+1;
        }
        else 
        {
            val2=b;
        }
    }
    else 
    {
        val1=a-1;
       
        if(prev==1)
        {
            val2=b+1;
        }
        else 
        {
            val2=b;
        }
    }
    if((val1+val2+1)==arr[i])
    {
        a=val1;
        b=val2;
        ans=rec(i+1,0,dn)%mod+rec(i+1,1,dn)%mod;
    }
    else 
    {
        ans=0;
    }
    return dp[i][dn][prev]=ans%mod;
}
void solve()
{

    cin>>n;
    arr.clear();
    memset(dp,-1,sizeof(dp));
    for(lli  i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        arr.push_back(x);
    }
    a=arr[0]-1;
    b=0;
    cout<<rec(1,0,0)+rec(1,1,0)<<endl;    

}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli t;cin>>t;while(t--)solve();
}