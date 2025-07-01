#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
vector<vector<pair<int,int>>> g;
vector<int> vis;// 0 stands for inf  and 1 stands for min dist , and 2 stands for second min distance 
vector<int > dist;

int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    dist.resize(n+1,inf);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        // g[b].push_back({a,c}); uncommnet this if undirected graph
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    vis[1]=0;
    dist[1]=0;
    while(pq.empty()==false)
    {
        auto x=pq.top();
        pq.pop();
        int node=x.second;
        int dt=abs(x.first);
        if(vis[node]==2)
        continue;
        if(vis[node]==0)
        {
            vis[node]=1;
            dist[node]=dt;
        }
        else if(vis[node]==1)
        {
           if(dist[node]<dt)
            {
                vis[node]=2;
                dist[node]=dt;
            }  
        }
        for(auto z:g[node])
        {
            int a=z.first;  //node
            int b=z.second; // weight
            if(vis[a]!=2)
            {
                int c=dt+b;
                pq.push({-c,a});
                // we are not modifing the dist array here because, we are not sure  it would be the most minimum or second minimum rather
                // than we are modifying it after popping because we know it would be the most minimum among all the distance in the priority queue
                // and once we do it after modifying we are setting vis array , which makes it unchangable in the future against the  nodes which pops out with different or larger distances 
           
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}