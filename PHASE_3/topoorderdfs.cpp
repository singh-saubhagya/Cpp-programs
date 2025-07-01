#include<bits/stdc++.h>
using namespace std;
vector<int> topo; vector<vector<int>> g;
vector<int > vis;
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
int main(){
    int n,m;
    cin>>n>>m;
    vis.resize(n+1,0);
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0)dfs(i);
    }
    reverse(topo.begin(),topo.end());
    if(flag)
    {
    for(auto x:topo)
    cout<<x<<" ";
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
    
}