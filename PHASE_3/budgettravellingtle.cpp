#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define inf 1e9
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
    dist.assign(n+1,vector<lli>(cp+1,inf));
    queue<pair<lli,lli>> q;
    q.push({0,st});
    dist[st][0]=0;
    while(q.empty()==false)
    {
        auto x=q.front();
        q.pop();
        lli a=x.first;// capacity
        lli b=x.second;//node
        lli cost;
        bool flag=false;
        // if(a==0 && b== 3)
        // {
        //     flag=true;
        // }
        for(lli i=a;i<=cp;i++)
        {
            // finding cost;
            lli liters=i-a;
            cost=liters*pc[b]+dist[b][a];
            // if(flag)
            // {
            //     cout<<"cost at literes"<<" "<<cost<<":"<<i<<endl;
            // }
            for(auto z:g[b])
            {
                lli t=z.first;  // ng node
                lli dt=z.second;// distance 
                if(dt<=i)
                {
                    lli temp=i-dt;
                    pair<lli,lli> y={temp,t};
                    if(cost<dist[t][temp])
                    {
                        dist[t][temp]=cost;
                        q.push(y);
                    }
                }
            }
        }
    }
    // cout<<"  ";
    // for(int i=0;i<=cp;i++)
    // cout<<i<<" ";
    // cout<<endl;
    // for(lli i=1;i<=n;i++)
    // {cout<<i<<" ";
    //     for(lli j=0;j<=cp;j++)
    //     {
    //         cout<<dist[i][j]<<" ";
    //     }cout<<endl;

    // }
    lli ans=LLONG_MAX;
    for(int i=0;i<=cp;i++)
    {
        ans=min(ans,dist[en][i]);
    }
    cout<<ans;
}