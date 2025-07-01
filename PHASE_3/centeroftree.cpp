#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dfs(int node,int pnt,vector<int> &depth,vector<int> &parent,vector<vector<int>> &g)
{
    depth[node]=depth[pnt]+1;
    parent[node]=pnt;
    for(auto x:g[node]){
        if(x!=pnt){
            dfs(x,node,depth,parent,g);
        }
    }
}
signed main()
{
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
    vector<int> depth;
    depth.assign(n+1,-1);
    vector<int> parent;
    parent.assign(n+1,0);
    dfs(1,0,depth,parent,g);

    int node1,dt1;
    dt1=-1;
    for(int i=1;i<=n;i++){
        if(depth[i]>dt1){
            node1=i;
            dt1=depth[i];
        }
    }   

    depth.assign(n+1,-1);
    dfs(node1,0,depth,parent,g);

    int node2,dt2;
    dt2=-1;
    for(int i=1;i<=n;i++){
        if(depth[i]>dt2){
            node2=i;
            dt2=depth[i];
        }
    }

    int dmt=depth[node2];// length of diameter;
    if(dmt&1){
        cout<<-1<<endl;
    }
    else{
        int x=dmt/2;
        int center=node2;
        for(int i=1;i<=x;i++)
        {
            center=parent[center];
        }
        cout<<center<<endl;
    }
}