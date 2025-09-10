#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
// dp 
void solve()
{
 int n;
 cin>>n;
 string str;
 cin>>str;
 vector<int>arr;
 arr.resize(n);
 for(int i=0;i<n;i++)
 cin>>arr[i];
 int dp[4]={0};
 for(int i=0;i<n;i++)
 {
    if(str[i]=='h')
    {
        dp[0]+=arr[i];
    }
    else if(str[i]=='a')
    {
        dp[1]=min(dp[0],dp[1]+arr[i]);
    }
    else if (str[i]=='r')
    {
        dp[2]=min(dp[1],dp[2]+arr[i]);
    }
    else if(str[i]=='d')
    {
        dp[3]=min(dp[2],dp[3]+arr[i]);
    }
    cout<<str[i]<<" ";
    for(int j=0;j<4;j++)
    {
        cout<<dp[j]<<" ";
    }
    cout<<endl;
 }
 cout<<dp[3]<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}