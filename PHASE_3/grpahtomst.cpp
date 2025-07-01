#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int findroot(int node , vector<int> &pnt){
    if(node==pnt[node])
    return node;
    else 
    {
        return pnt[node]=findroot(pnt[node],pnt);
    }
}
 int  main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edge; 
    if(m<n-1)\
    {
        cout<<"Minimum spanning tree not possible for the given graph"<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});

    }
    sort(edge.begin(),edge.end());
    vector<int> pnt,rank;
    pnt.resize(n+1);
    rank.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        pnt[i]=i;
        rank[i]=1;
    }
    int ne=0;// no of edges 
    int cost=0;
    for(auto x:edge)
    {
        int wt=x.first;
        int a=x.second.first;
        int b=x.second.second;
        int aroot=findroot(a,pnt);
        int broot=findroot(b,pnt);
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
        cout<<"Minimum spanning tree not possible for the given graph"<<endl;
    }
    else 
    {
        cout<<"Minimum spanning is feasiable with cost "<<cost<<endl;
    }
    return 0;
}