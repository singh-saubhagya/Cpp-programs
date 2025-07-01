#include<bits/stdc++.h>
using namespace std;
vector<int> order;
void dfs(int node,vector<vector<int>> &g, int n,vector<int> & vis,vector<int>& depth,int pnt,vector<int> &parent,vector<int> &subtree)
{   

    vis[node]=1;
    depth[node]=depth[pnt]+1;
    parent[node]=pnt;
    order.push_back(node);
    for(auto x:g[node])
    {
        if(vis[x]==0)
        {
            dfs(x,g,n,vis,depth,node,parent,subtree);
            subtree[node]+=subtree[x];// we are calculating this after it has backtrack , so it has calculated the size of subtree rooted at x 
                                      // in the base case the node has no neighbour , so  size of subtree will remain 1 and get addded after backtraking to its parent 

        }

    }
    return;
}

signed main()
{
    int n;
    cin>>n;
    int m=n-1;
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vis;
    vector<int> depth;
    vector<int>subtree;
    vector<int> parent;

    
    depth.assign(n+1,-1);
    parent.assign(n+1,0);
    vis.assign(n+1,0);
    subtree.assign(n+1,1);


    dfs(1,g,n,vis,depth,0,parent,subtree);


    cout<<"Traversing order"<<endl;
    for(auto x:order)
    cout<<x<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    cout<<i<<" has depth : "<<depth[i]<<endl;
    cout<<endl;
    for(int i=1;i<=n;i++)
    cout<<i<<"'s parent is : "<<parent[i]<<endl;
    cout<<endl;

    for(int i=1;i<=n;i++)
    cout<<i<<" has subtree size of : " <<subtree[i]<<endl;
}