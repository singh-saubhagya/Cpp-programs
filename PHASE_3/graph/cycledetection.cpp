#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,m;
vector<vector<lli>> gph;
vector<lli> visited;
// 1 black
// 0 for gray
// -1 for white
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
bool checkcycle (lli i)
{
    visited[i]=0;//grey
    for(auto it:gph[i])
    {
        if(visited[it]==-1)
        {
           if( checkcycle(it) )
           {
            return true;
           } 
        }
        else if (visited[it]==0)
        {
            return true;// cycle found
            //cycle exist as it is pointing to the node whose neighbours are not completely visited
            // it is pointing to the grey node means it node is derived from the grey node(grey node is parent of it)
        }
    }
    visited[i]=1;
    return false;
}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  visited.resize(n+1,-1);
  bool flag=false;
  for(lli i=1;i<=n;i++)
  {
    if(visited[i]==-1)// white
    {
    if(checkcycle(i))
    {
        flag=true;
        break;
    }
    }
  }
  if(flag)
  cout<<"true";
  else cout<<"false";
}