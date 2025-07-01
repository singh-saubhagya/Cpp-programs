#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli ;
lli  findroot(lli  node, vector<lli > &pnt)
{
    if(node==pnt[node])
    return node;
    else 
    {
        return pnt[node]=findroot(pnt[node],pnt);
    }
}
signed main(){
    lli  t;
    cin>>t;
    while(t--)
    {
        lli  n;
    cin>>n;
    set<pair<lli ,lli >> edge;
    map<lli ,pair<lli ,lli >> temp;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(lli  i=1;i<=n-1;i++)
    {
        lli  a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
        temp[c]={a,b};
    }
    vector<lli > rank,pnt;
    rank.resize(n+1);
    pnt.resize(n+1);
    for(lli  i=1;i<=n;i++)
    {
        rank[i]=1;
        pnt[i]=i;
    }
    lli  ans=0;
    while(pq.empty()==false)
    {
        auto it=pq.top();
        pq.pop();
        auto i=it.second;
        lli  a=i.first;
        lli  b=i.second; 
        // cout<<"edge :"<<a<<" "<<b<<endl;
        // cout<<"wt "<<it->first<<endl;
        lli  wt=it.first;
        lli  aroot=findroot(a,pnt);
        lli  broot=findroot(b,pnt); 
           
            // cout<<aroot<<" "<<broot<<endl;
            // cout<<rank[aroot]<<" "<<rank[broot]<<endl;
        if(aroot!=broot)
        {   
           
            ans+=wt*(rank[aroot]*rank[broot]);
            if(rank[aroot]>=rank[broot])
            {
                pnt[broot]=aroot;
                rank[aroot]+=rank[broot];
            }
            else 
            {
                pnt[aroot]=broot;
                rank[broot]+=rank[aroot];
            }
        }
    }
    cout<<ans<<endl;
    }
    
}