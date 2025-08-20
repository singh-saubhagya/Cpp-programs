#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t' 
vector<int> arr;
int n;
int dp[110][6];
// 1 sport 2 contest ,, 0 rest 
int rec(int i, int act)
{
    if(i==n)
    return 0;

    if(dp[i][act]!=-1)
    return dp[i][act];
    // take rest
    int ans=1+rec(i+1,0);

    // do sport 
    if((arr[i]==2 || arr[i]==3) && act !=1)
    ans=min(ans,rec(i+1,1));

    // give contest 
    if((arr[i]==1 || arr[i]==3) && act!=2)
    ans=min(ans,rec(i+1,2));

    if(arr[i]==0)
    ans=min(ans,1+rec(i+1,0));

    return dp[i][act]=ans;

}
void solve()
{
 
 cin>>n;
 arr.resize(n);
 for(int i=0;i<n;i++)
 cin>>arr[i];
 memset(dp,-1,sizeof(dp));
 cout<<rec(0,0);
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}