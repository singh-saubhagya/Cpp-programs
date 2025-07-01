#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dfs(int node,vector<vector<int>> &g,int parent,vector<int> &order)
{
    order.push_back(node);
    for(auto x:g[node]){
        if(x!=parent){
            dfs(x,g,node,order);
        }
    }
}
int parentof(int node , vector<int> &par)
{
    if(par[node]==node)
    return node;
    else 
    {
        int x=parentof(par[node],par);
        // backtracking 
        par[node]=x;  
        return par[node];
    }
  
}
signed main(){
    int n;
    cin>>n;

    int q;
    cin>>q;
    vector<int> rank;
    rank.assign(n+1,1);

    vector<int> par;
    par.resize(n+1);

    for(int i=1;i<=n;i++)
    par[i]=i;
    vector<vector<int>> g;
    g.resize(n+1);
    while(q--){
        int a,b;
        int com;

        cin>>com>>a>>b;

        a=parentof(a,par);
        b=parentof(b,par);
        if(com)
        {
            if(a==b)
            cout<<1<<endl;
            else cout<<0<<endl;
        }
        else 
        {
           if(a!=b)
        {
            if(rank[a]==rank[b]){
                rank[b]+=rank[a];
                par[a]=b;
            }
            else if(rank[a]<rank[b]){
                par[a]=b;
                rank[b]+=rank[a];
            }
            else 
            {
                par[b]=a;
                rank[a]+=rank[b];
            }
        }   
        }
      
   
    }
   
    
}