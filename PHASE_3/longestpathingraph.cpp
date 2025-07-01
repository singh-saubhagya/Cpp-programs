#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> g;
vector<int> dp;vector<int> topo;
bool flag=true;
void dfs(int node){
    vis[node]=1;
    for(auto x:g[node])
    {
        if(vis[x]==0)
        dfs(x);
        else if(vis[x]==1)
        {
            flag=false;
        }
    }
    vis[node]=2;
    topo.push_back(node); 
}
int rec(int node)
{
    int ans=1;
    for(auto x:g[node])
    {
      ans=max(ans,1+rec(x));
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vis.resize(n+1,0);
    g.resize(n+1);
    dp.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0)dfs(i);
    }
    int ans=LLONG_MIN;
    for(auto i:topo)
    {
        ans=max(ans,rec(i));
        dp[i]=ans;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dp[i]<<endl;// printing longest path possible starting from node 1 
    }
  
    return 0;
}