#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,m;
vector<vector<lli>> gph;
vector<lli> visited;
lli color=0;
vector<lli> neigh;
void input()
{
   
    cin>>n;
    gph.resize(n+1);

    for(lli i=1;i<=n-1;i++)
    {
        lli a,b;
        cin>>a>>b;
        gph[a].push_back(b);
        gph[b].push_back(a);     
    }
}
void dfs(lli s)
{
    if(visited[s]==0)
    {
        
            lli remneig=neigh[s]-1;
            lli colorreq=remneig+1-(color-1);
            if(colorreq>0)
            {
            color=color+colorreq;
            }
        
        
    visited[s]=1;
    }
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
  visited.resize(n+1,0);
  color=1;
  neigh.resize(n+1);
  for(lli i=1;i<=n;i++)
  {
    neigh[i]=gph[i].size();
  }
  auto m=max_element(neigh.begin(),neigh.end());
  // for(lli i=1;i<=n;i++)
  // {
  //   if(!visited[i])
  //   {
  //     color++;
  //     visited[i]=1;
  //     dfs(i);
  //   }
    
  // }
  int x=*m+1;



  cout<<x;
}