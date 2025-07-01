
// program to print check the reachability of pair of nodes.
// i to i is reachable and all the edges are reachable, we are using dist array, 
#include<bits/stdc++.h>
using namespace std;
#define inf 100
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int ,int>>> g;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    vector<vector<int>> dist;
    dist.assign(n+1,vector<int>(n+1,0));
    

    for(int i=1;i<=n;i++){
        dist[i][i]=1;
       
        for(auto x:g[i])
        {
            int a = x.first;
            int b = x.second;
            dist[i][a]=1;// in case of multiple edges are present between two nodes
           
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((dist[i][k] & dist[k][j] )| dist[i][j])
                {
                    dist[i][j]= 1;
                    
                }
            }
        }
    }
    cout<<"  ";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
  
   
}