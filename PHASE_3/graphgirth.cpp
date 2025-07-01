#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int ans=inf;
// below is the solution , where i am trying to store all the possbile cyles , but it is not working.
void bfs(int node,vector<vector<int>> g,int n)
{   
    vector<int> dist;
    dist.assign(n+1,inf);
    queue<int> q;
    q.push(node);
    dist[node]=0;
    while(q.empty()==false)
    {
        auto x=q.front();
        q.pop();
        for(auto z:g[x])
        {
            if(dist[z]==inf)
            {
                q.push(z);
                dist[z]=dist[x]+1; 
            }
            else if(dist[z]-dist[x]==1 || dist[z]-dist[x]==0)// this condition is use to check one edge parent child conflict
            {
                ans=min(ans,dist[z] + dist[x] + 1);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g;
    g.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i,g,n);
    }
    if(ans==inf)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;
    return 0;
}


























































// void dfs(vector<vector<int>> g, vector<int> &vis, int node , vector<int> &pnt,vector<pair<int,int>> &cycle)
// {
//     vis[node]=1;
//     for(auto x:g[node])
//     {
//         if(vis[x]==0)
//         {
//             pnt[x]=node;
//             dfs(g,vis,x,pnt,cycle);
//         }
//         else if(vis[x]==1)
//         {
//             if(pnt[node]!=x)
//             {
//                 //cycle exist
//                 cycle.push_back({node,x});
//             }
//         }
//     }
//     vis[node]=2;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> g;
//     g.resize(n+1);
//     vector<vector<int>> matx;
//     matx.resize(n+1,vector<int>(n+1));
//     for(int i=0;i<m;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         g[a].push_back(b);
//         matx[a][b]=1;
//         matx[b][a]=1;
//         g[b].push_back(a);
//     }
//     vector<int> vis;
//     vis.assign(n+1,0);
//     vector<int> pnt;
//     pnt.resize(n+1);
//     vector<pair<int,int>> cycle;
//     for(int i=1;i<=n;i++)
//     {
//         if(vis[i]==0)
//         {
//             pnt[i]=0;
//             dfs(g,vis,i,pnt,cycle);
//         }
//     }
//     int ans=n;
    
//     for(auto x : cycle) 
//     {
//         int node=x.first;
//         int sz=1;
//         while(node!=x.second)
//         {
//             sz++;
//             node=pnt[node];
//             if(matx[node][x.second]==1)
//             {
//                 sz++;
//                 break;
//             }   
//         }
//         ans=min(ans,sz);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<i<<": "<<pnt[i]<<" ";
//     }
//     for(auto x:cycle)
//     {
//         cout<<x.first<<" "<< x.second <<endl;
//     }
//     if(cycle.size()>0)
//     cout<<ans<<endl;
//     else
//     cout<<-1;
//     return 0;
// }