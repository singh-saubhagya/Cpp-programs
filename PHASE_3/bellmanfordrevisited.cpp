#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define inf 1e18


signed main(){
    lli n,m;
    cin>>n>>m;
    vector<pair<pair<lli,lli>,lli>> edge;
    vector<lli> dist;
    vector<vector<lli>> g;
    g.resize(n+1);
    for(lli i=0;i<m;i++)
    {
        lli a,b,c;
        cin>>a>>b>>c;
        edge.push_back({{a,b},-c});
        g[a].push_back({b});
    }
   
   
   
    dist.assign(n+1,inf);
    dist[1]=0;
    for(lli i=1;i<=n-1;i++)
    {
        for(auto x:edge)
        {
            lli a,b,c;
            a=x.first.first;//node
            b=x.first.second;// node 
            c=x.second;// weight
            lli dt=dist[a]+c;
            if(dt<dist[b])
            {
                dist[b]=dt;
            }
            
        }
    }

    
 
        bool neg=false;
        for(auto x:edge)
        {
            lli a,b,c;
            a=x.first.first;//node
            b=x.first.second;// node 
            c=x.second;// weight
            lli dt=dist[a]+c;
            if(dt<dist[b])
            {
                
               neg=true;
            }
            
        }
        if(neg) cout << "-1\n";
	    else {
		assert(dist[n] != 1e18);
		cout << -dist[n] << "\n";
	}
   
}               