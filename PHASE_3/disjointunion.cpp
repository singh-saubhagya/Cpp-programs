#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int parentof(int node , vector<int> &par){
    if(par[node]==node)
    return node;
    else 
    {
        int x=parentof(par[node],par);
        par[node]=x;
        return x;
    }
}
signed main(){

    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> par,rank;
    par.resize(n+1);
    rank.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        rank[i]=1;
    }
    while(q--){
        int com,x,y;
        cin>>com>>x>>y;
       
       
            x=parentof(x,par);
            y=parentof(y,par);
          
        if(com){
            
            if(x==y)
            cout<<1<<endl;
            else 
            cout<<0<<endl;
        }
        else 
        {
            if(x!=y)
            {
                if(rank[x]>=rank[y]){
                    par[y]=x;
                    rank[x]+=rank[y];
                }
                else 
                    {par[x]=y;
                    rank[y]+=rank[x];}
            }

           
        }
    }
}