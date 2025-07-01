#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &g,int parent,vector<int> &order)
{
    order.push_back(node);
    for(auto x:g[node]){
        if(x!=parent){
            dfs(x,g,node,order);
        }
    }
}
int parentof(int node,vector<int>&par){
    if(par[node]==node)
    return node;
    int cur=node;
    while(par[cur]==cur){
        cur=par[cur];
    }
    return cur;
}
signed main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> par;
    par.resize(n+1);
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<=n;i++)
    par[i]=i;
    while(q--){
        int a,b;
        cin>>a>>b;
        // find parent of a and b , then set them
        a=parentof(a,par);
        b=parentof(b,par);
        // par[a]=a and par[b]=b
        par[a]=b;   
        // par[a]=b and par[b]=b
        g[a].push_back(b);
        g[b].push_back(a);

    }
    vector<int> order;
    dfs(5,g,0,order);
    for(auto x:order)
    cout<<x<<" ";
}