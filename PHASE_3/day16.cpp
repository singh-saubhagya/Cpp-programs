#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
signed main(){
    int n;
    cin>>n;
    map<int,vector<int>> m;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x].push_back(i);
        arr.push_back(x);
    }
    int a,b;
    cin>>a>>b;
    vector<vector<pair<int,int>>> g;
    g.resize(n+m.size()+1);
    for(int i=1;i<n;i++){
        g[i].push_back({i-1,a});
        g[i-1].push_back({i,a});
    }
    auto it=m.begin();
    for(int i=0;i<m.size();i++)
    {
        int nw=n+i;
        int val=it->first;
        vector<int> idx=it->second;
        for(auto &v:idx){// & is faster 
            g[nw].push_back({v,b});
            g[v].push_back({nw,0});
        }
        it++;
    } 
    vector<int> dist;
    dist.assign(n+m.size()+1,inf);
    vector<bool> marked(n+m.size()+1,false);
    priority_queue<pair<int,int>> pq;
    
        pq.push({0,0});
        dist[0]=0;
    
    while(pq.empty()==false){
        auto val=pq.top();
        pq.pop();
        int y=val.second;
        if(marked[y]==true)
        continue;
        marked[y]=true;

        for(auto x:g[y]){
            int node=x.first;
            int wt=x.second;
            int dt=dist[y]+wt;
            if(dt<dist[node]){
                dist[node]=dt;
                pq.push({-dt,node});
            }
        }

    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<": "<<dist[i]<<endl;
}