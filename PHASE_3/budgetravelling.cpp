#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define inf 1e9
/*
Q1.Why using dijkstra, because 

1. if we bfs to minimize the cost, duplicate entries are also added to the queue , 
2. if original bfs we were using visited array to not to visit the same state again , 
but in this problem we are using we are not using the visited array because we know at first time the state {node,cap} is visited does not have optimzied value

Q2.Why are we using the state as node*capacity
Because we the aim of the problem is to minimize the cost , and to do so we can fuel our car more on the city which has cheaper fuel price
thus we have to maintain the all the states and relax with them the reamining states for ex:

for a node 3 we will have states as (3,0) , (3,1) , (3,2) ,(3,3) , (3,4) where first argument is the city and the second argument is the capacity
(tank has max capacity of 4), thus  we will relax all the neigbours of the node 3 with all the states here. 
for better understand refer to example in the notebook

*/
signed main(){
    lli n,m;
    cin>>n>>m;
    vector<vector<pair<lli,lli>>> g;
    g.resize(n+1);
    for(lli i=0;i<m;i++)
    {   
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});

    }
    vector<lli> pc;//petrol cost at each city;
    pc.resize(n+1);
    for(lli i=1;i<=n;i++)
    {
        cin>>pc[i];
    }
    lli st,en,cp;
    cin>>st>>en>>cp;
    vector<vector<lli>> dist;
    vector<vector<bool>> marked; 
    dist.assign(n+1,vector<lli>(cp+1,inf));
    marked.assign(n+1,vector<bool>(cp+1,false));
    dist[st][0]=0;
    priority_queue<pair<lli,pair<lli,lli>>> pq;
    pq.push({0,{st,0}});// stores ,cost,{node, capacity}
    
    while(pq.empty()==false){
        auto it=pq.top();
        pq.pop();
        
        lli cost=-it.first;
        lli node=it.second.first;
        lli cap=it.second.second;
        if(marked[node][cap]==true)
        {
            continue;
        }
       
        marked[node][cap]=true;
        // using minimum optimizaion should not be done;
        for(auto ng:g[node]){
            lli x=ng.first;// neigh node
            lli y=ng.second;// fuel req to move
            if(cap>=y){
                lli rem=cap-y;
                if(marked[x][rem]==false){// marking means that dist for that node is finalized.
                    if(dist[x][rem]>cost)
                    {
                        pq.push({-cost,{x,rem}});
                        dist[x][rem]=cost;
                    }
                }
            }
        }
        // now refilling 
        if(cap<cp && marked[node][cap+1]==false){
            
            lli newcost=pc[node]+cost;
            if(dist[node][cap+1]>newcost)
            {
                pq.push({-newcost,{node,cap+1}});
                dist[node][cap+1]=newcost;
            }
        }
    }
    cout<<dist[en][0];
}