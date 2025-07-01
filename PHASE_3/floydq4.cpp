// to detect cycles , for this we will initialize all the dist will inf even for dist[i][i], so that if there was any cylce at some node i, it will store its distance at dist[i][i]

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
    dist.assign(n+1,vector<int>(n+1,inf));
    

    for(int i=1;i<=n;i++){
        dist[i][i]=inf;
       
        for(auto x:g[i])
        {
            int a = x.first;
            int b = x.second;
            dist[i][a]=min(dist[i][a],b);// in case of multiple edges are present between two nodes
           
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
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
            if(dist[i][j]!=inf)
            cout<<dist[i][j]<<" ";
            else
            cout<<"n"<<" ";
        }
        cout<<endl;
    }
  // to print the minimum cycle take minimun among all the i,i 
   
}