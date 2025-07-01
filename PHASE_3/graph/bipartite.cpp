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
    gph.resize(n);
    for(lli i=1;i<=m;i++)
    {
        lli a,b;
        cin>>a>>b;
        gph[a].push_back(b);
        gph[b].push_back(a);     
    }
}
bool checkbipartite(lli s,lli color)
{
    
        visited[s]=color;
        for(auto it:gph[s])
        {
            if(!visited[it])
            {
                if(!checkbipartite(it,3-color))
                return false;
            }
            else if(color==visited[it])
            {
            return false;
            }
        }
       return true;

}
signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  bool flag=true;
  visited.resize(n,0);
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
    if(!checkbipartite(i,1))
    {
    flag =false;
    break;
    }
    }

  } 
  if(flag)
  cout<<"True"<<endl;
  else
  cout<<"False"<<endl;
}