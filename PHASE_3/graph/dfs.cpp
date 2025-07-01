#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,m;
vector<vector<lli>> gph;
vector<lli> visited;
void input()
{
    cin>>n>>m;
    gph.resize(n+1);
    for(lli i=1;i<=m;i++)
    {
        lli a,b;
        cin>>a>>b;
        gph[a].push_back(b);     
    }
}
void dfs(lli s)
{
    
    visited[s]=1;
    for(lli i:gph[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  lli source;
  cin>>source;
  visited.resize(n+1,0);
  dfs(source);
  cout<<endl;
  for(lli i=1;i<=n;i++)
  {
    
    cout<<visited[i]<<tab;
  }
}