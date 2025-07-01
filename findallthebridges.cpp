/*
cf blog link:https://codeforces.com/blog/entry/68138


there are two types of edges in a dfs tree , one in span edge and the other is backedge,
a bridge is a span edge with a cond , for a edge u-v, to be a bridge there must not be any backedge connecting ancestor of u to descendant of v , 
so presence of bridge concludes to visit v and its descendant we have to go via u-v edge , or else there will not be any path,

Component idea; no of component in the graph , increasese if we remove bridge in the graph.

the bridges will be same irrespective of from where we start dfs , 
pnt[node]-node: find the no of backedges , going over the this edge.
dp[node]: no of backedges going up from node ( the backedge can end at any ancestor of node but not its parent)
dp[node]: x-y+z;
x:no of backedges from going up starting from node(will be added as this will contribute to ans)
y:no of backedges going down starting from node(this be, will not pass the pnt[node]-node edge . )
z: ∑dp[v], where v is child of u and summation denotes all the nodes of u, (this will pass the pnt[node]-node edge as we have defined dp[v], will end at any ancestor of node u but not at u)
// so for ex, there are u-v-a, a is child of v , so if dp[a]> 1 implies , there is backedge ending at u or any ancestor of u atleast.
suppose the node has edge as  node-x
amd vis[x]=1 , then this is a backedge in the upward dn 
and the revers x-node is a backedge in the downward dn  

there are no forward edges in undirected graph, for example a-b are two nodes in between they have forward edge ,
so it must follow the condition vis[b]=2 and vis[a]=1, this is a contradiction, because if vis[b]=2 is true, 
then it must visit the a node , via that edge and marked vis[a]=2 first , then itself , 
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> order;
vector<int> up;
vector<int> down;
vector<vector<int>> child;
void dfs(int node ,int parent, vector<vector<int>> & g ,vector<int> & pnt, vector<int > &vis,vector<int> & cycle){
    pnt[node]=parent;
    vis[node]=1;
    for(auto x:g[node]){
        if(vis[x]==0)
        { 
          child[node].push_back(x);
          dfs(x,node,g,pnt,vis,cycle);
          
        }
        else if(x!=pnt[node] && vis[x]==1){
            
            up[node]+=1;//backedge in upward dn
            down[x]+=1;// backedge in downward dn
        }
    }
    vis[node]=2;
    order.push_back(node);
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g;
    g.resize(n+1);
    vector<pair<int,int>> edge;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge.push_back({a,b});
    }
    vector<int> pnt;
    pnt.assign(n+1,0);
    vector<int> vis;
    vis.assign(n+1,0);
    vector<int> cycle;
    cycle.assign(n+1,0); 
    up.assign(n+1,0);
    down.assign(n+1,0);
    child.resize(n+1);
    dfs(12,0,g,pnt,vis,cycle);

    
    // for(auto x:order)
    // cout<<x<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" : ";
    //     for(auto x:child[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"   "<<"up"<<" "<<"down"<<endl;

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<" : "<<up[i]<<" "<<down[i]<<endl;
    // }
    vector<int> dp;
    dp.assign(n+1,0);
    for(auto x:order)
    {
        dp[x]=up[x]-down[x];
        for(auto y:child[x])
        {
            dp[x]+=dp[y];
        }
    }
    // for(auto x:order)
    // {
    //     cout<<x<<" : "<<dp[x]<<endl;
    // }
    set<pair<int,int>> bridge;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==0 && pnt[i]!=0)
        {
            bridge.insert({min(pnt[i],i),max(pnt[i],i)});
        }
    }
    for(auto x:bridge)
    cout<<x.first<<"-"<<x.second<<endl;
}
    
/*

input:
12 16
1 3 
3 5 
5 7 
3 6 
6 2 
2 8 
2 4 
4 10
1 9 
9 11 
11 12
1 5 
3 7 
3 8 
1 6 
9 12 


output:
1-9
2-4
4-10
*/