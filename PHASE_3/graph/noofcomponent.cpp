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
void dfs(lli s,lli color)
{
    
    visited[s]=color;
    for(lli i:gph[s])
    {
        if(!visited[i])
        {
            dfs(i,color);
        }
    }
}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  visited.resize(n+1,0);
  lli noofcomp=0;
  for(lli i=1;i<=n;i++)
  {
    if(!visited[i])
    {
        noofcomp++;
        dfs(i,noofcomp);
    }
  }
  vector<vector<lli>> arr;
  arr.resize(noofcomp+1);
  for(lli i=1;i<=n;i++)
  {
    arr[visited[i]].push_back(i); 
  }
  for(lli i=1;i<=noofcomp;i++)
  {
    for(auto it:arr[i])
    {
        cout<<it<<tab;
    }
    cout<<endl;
  }
  cout<<endl;
 
}