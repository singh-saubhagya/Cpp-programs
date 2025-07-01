#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli n,m;
vector<vector<lli>> gph;
vector<lli> visited;
vector<lli> num;
lli z=0;
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
void dfs(lli i,lli count)
{
    visited[i]=count;
    z++;
    for(auto it:gph[i])
    {
        if(!visited[it])
        {
            dfs(it,count);
        }
    }
}

signed main()
{
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  visited.resize(n+1,0);
  lli count=0;
  for(lli i=1;i<=n;i++)
  {
    if(!visited[i])
    {
        count++;
        dfs(i,count);
        num.push_back(z);
        z=0;
    }
  }
  if(count==0)
  {
    cout<<"0";
    
  }else
  {
    lli sum=0;
    vector<lli> presum;
    for(lli i=0;i<num.size()-1;i++)
    {
        sum+=num[i];
        presum.push_back(sum);
    }
    for(int i=1;i<num.size();i++)
    {
        sum=presum[i-1]*num[i];
    }
    cout<<sum;
    

}
}