#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
lli  findroot(lli  node , vector<lli > &pnt){
    if(node==pnt[node])
    return node;
    else 
    {
        return pnt[node]=findroot(pnt[node],pnt);
    }
}
 lli   main(){
    lli  n,m;
    cin>>n>>m;
    vector<pair<lli ,pair<lli ,lli >>> edge; 
    if(m<n-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(lli  i=1;i<=m;i++)
    {
        lli  a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});

    }
    sort(edge.begin(),edge.end());
    vector<lli > pnt,rank;
    pnt.resize(n+1);
    rank.resize(n+1);
    for(lli  i=1;i<=n;i++)
    {
        pnt[i]=i;
        rank[i]=1;
    }
    lli  ne=0;// no of edges 
    lli  cost=0;
    for(auto x:edge)
    {
        lli  wt=x.first;
        lli  a=x.second.first;
        lli  b=x.second.second;
        lli  aroot=findroot(a,pnt);
        lli  broot=findroot(b,pnt);
        if(aroot!=broot)// not in the same componet
        {
            // add the edge 
            cost+=wt;
            if(rank[aroot]>=rank[broot])
            {
                pnt[broot]=aroot;
                rank[aroot]+=broot;
            }
            else 
            {
                pnt[aroot]=broot;
                rank[broot]+=aroot;
            }
            // total no of edges will be increase by 1 , after addition of current edge and we know in a mst , there can be no more than n-1 edges so 
            ne++;
            if(ne==n-1)
            {
                break;
            }
        }
    }
    if(ne<n-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else 
    {
        cout<<cost<<endl;
    }
    return 0;
}