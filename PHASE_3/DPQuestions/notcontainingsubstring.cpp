// 1011

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'  
int n;
int dp[100002][10];
int rec(int i,int sub)
{
    if(sub==8) // pruning
    return 0;

    if(i==n+1)
    {   
        return 1;// base case 
    }

    if(dp[i][sub]!=-1)
    return dp[i][sub];
    int ans=0;
    if(sub==0)
    {
        ans=rec(i+1,1) + rec(i+1,0);
    }
    else if(sub==1)
    {
        ans=rec(i+1,sub)+rec(i+1,2);
    }
    else if (sub==2)
    {
        ans=rec(i+1,5)+rec(i+1,0);
    }
    else if(sub==5)
    {
        ans=rec(i+1,8)+rec(i+1,2);
    }
    return dp[i][sub]=ans;
}
void solve()
{
  
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0);
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}