

// to print the shortet path. we go to i to j via a path i,x,y,j, so parent of this path will be y , and parent of path i,x,y will be x and of i,x ,will be i, so likewise we will store this path and print it;
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
    vector<vector<int> > pnt;
    pnt.assign(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
        pnt[i][i]=i;
        for(auto x:g[i])
        {
            int a = x.first;
            int b = x.second;
            dist[i][a]=min(dist[i][a],b);// in case of multiple edges are present between two nodes
            pnt[i][a]=i;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j]= dist[i][k] + dist[k][j];
                    pnt[i][j]=pnt[k][j];
                }
            }
        }
    }
    int st;
    int en;
    cin>>st>>en;
    vector<int> temp; 
    temp.push_back(en);
    while(en!=st)
    {
       
        int x=pnt[st][en];
        temp.push_back(x);
        en=x;

    }   
    reverse(temp.begin(),temp.end());
    for(auto x:temp)
    {
        cout<<x<<" ";
    }
   
}