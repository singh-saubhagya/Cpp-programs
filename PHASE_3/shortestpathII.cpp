#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
#define inf 1e18
signed main()
{
    lli n,m,q;
    cin>>n>>m>>q;
    vector<vector<lli>> dist;
    dist.assign(n+1,vector<lli>(n+1,inf));
    for(lli i=0;i<m;i++){
        lli a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }   
    for(lli k=1;k<=n;k++){
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        lli a,b;
        cin>>a>>b;
        lli x=dist[a][b];
      
        if(x==inf){
            cout<<"-1"<<endl;
        }
        else 
        cout<<x<<endl;
    }
}