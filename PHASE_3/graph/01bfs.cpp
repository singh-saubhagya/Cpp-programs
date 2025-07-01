#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define inf 1e9
using ii=pair<lli,lli>;
lli n,m;
vector<vector<ii>> gph;
vector<lli> dist;
vector<lli> visited;

void input()
{
    cin>>n>>m;
    dist.resize(n+1,inf);
    gph.resize(n+1);
    visited.resize(n+1,0);
    for(lli i=1;i<=m;i++)
    {
        lli a,b,c;
        cin>>a>>b>>c;
        gph[a].push_back({b,c});     
    }
}
void bfs(lli s)
{
    deque<lli> q;
    dist[s]=0;
    q.push_front(s);
    while(!q.empty())
    {
        lli cur=q.front();
        q.pop_front();
        if(visited[cur])
        continue;
        visited[cur]=1;
        for(ii it:gph[cur])
        {
            if(dist[cur]+ it.second< dist[it.first])
            {
                dist[it.first]=dist[cur]+ it.second;
                if(it.second==0)
                {
                    q.push_front(it.first);
                }
                else
                {
                    q.push_back(it.first);   
                }
            }
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
  bfs(source);
  for(lli i=1;i<n+1;i++)
  {
    cout<<i<<":"<<dist[i]<<endl;
  }
}