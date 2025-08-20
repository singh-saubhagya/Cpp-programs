#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;

void dfs(lli  node, pair<lli ,lli > parent, vector<pair<lli ,lli >> &pnt,vector<vector<pair<lli ,lli >>> &g)
{
    pnt[node]=parent;
    for(auto x:g[node])
    {
        if(x.first!=parent.first)
        {
            dfs(x.first,{node,x.second},pnt,g);
        }
    }
}
void solve()
{
    lli  n,q;
    cin>>n>>q;
    vector<lli > col;
    col.resize(n+2);
    col[0]=0;
    for(lli  i=1;i<=n;i++)
    cin>>col[i];
    vector<vector<pair<lli ,lli >>> g;
    g.resize(n+2); lli  ans=0;
    for(lli  i=1;i<=n-1;i++)
    {
        lli  a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        if(col[a]!=col[b])
        ans+=c;
    }
    vector<pair<lli ,lli >> pnt;
    pnt.resize(n+2);
    dfs(1,{0,0},pnt,g);
   
    vector<map<lli,lli>>  cs;// color sum;
    cs.resize(n+2);
   
    for(lli  i=1;i<=n;i++)
    {
        for(auto x:g[i])
        {
            
            lli  node=x.first;
            lli  color=col[node];
            lli  c=x.second;// weight
            if(node!=pnt[i].first)
            {
                
                cs[i][color]+=c;
            }
            
        }
    }
   
    while(q--)
    {
       lli  node,nc;
       cin>>node>>nc;
       lli  oc=col[node];
       if(oc==nc)
       {cout<<ans<<endl;
       continue;}
       ans+=cs[node][oc];
    //    cout<<"node : "<<node<<". color chaned from. "<<oc<<" "<<nc<<endl;
    //    cout<<"old colr added "<<cs[node][oc]<<endl;
       ans-=cs[node][nc];
    //    cout<<"new colr subtracted"<<" "<<cs[node][nc]<<endl;

       lli  parent=pnt[node].first;
       cs[parent][oc]-=pnt[node].second;
       cs[parent][nc]+=pnt[node].second;

       if(col[parent]==oc)
       {
        ans+=pnt[node].second;
       }
       else if(col[parent]==nc)
       {
        ans-=pnt[node].second;
       }
       col[node]=nc;
       cout<<ans<<endl;
    }
   
}
signed main()
{
    lli  t;cin>>t;
    while(t--)solve();
}