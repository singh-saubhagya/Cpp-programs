#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<int> arr;
vector<vector<int>> g;
int n;
int dp[200010];
int rec(int i)
{
    if(i<=0)
    return 0;
    
    if(dp[i]!=-1)
    return dp[i];

    int sum=0;

    int val=arr[i];
    int val2=g[val].size();

    sum=max(rec(i-1),sum);
   
    int idx=lower_bound(g[val].begin(),g[val].end(),i)-g[val].begin();
    int seidx=idx-(val-1);
    if(seidx>=0)
    {
        int val3=g[val][seidx];
        val3--;
        sum=max(val+rec(val3),sum);
    } 
    
    return dp[i]=sum;


}
void solve()
{

  cin>>n;
  memset(dp,-1,sizeof(dp));
  arr.clear();
  g.clear();
  
  arr.resize(n+2);
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
  g.resize(n+3);
  for(int i=1;i<=n;i++)
  {
    int val=arr[i];
    g[val].push_back(i);
  }
  cout<<rec(n)<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}