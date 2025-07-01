#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void dfs(int node, int pnt,vector<int> &depth,vector<vector<int>> & g,int n)
{
    depth[node]=depth[pnt]+1;
    for(auto x:g[node])
    {
        if(x!=pnt)
        {
            dfs(x,node,depth,g,n);
        }
    }
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int a=1;
    vector<int> depth;
    depth.assign(n+1,-1);
    dfs(1,0,depth,g,n);
    int node,dt;
    dt=-1;
    for(int i=1;i<=n;i++){
        if(depth[i]>dt)
        {
            node=i;
            dt=depth[i];
        }
    }
    depth.assign(n+1,-1);
    dfs(node,0,depth,g,n);
    int node2,dt2;
    dt2=-1;
    for(int i=1;i<=n;i++){
        if(depth[i]>dt2)
        {
            node2=i;
            dt2=depth[i];
        }
    }
    cout<<dt2<<endl;
}