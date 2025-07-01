#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int findroot(int node,vector<int> &pnt)
{
   if(node==pnt[node])
   {
       return node;
   }
   {
       int x=findroot(pnt[node],pnt);
       pnt[node]=x;
       return x;
   }
}
signed main(){
   int n,m,q;
   cin>>n>>m>>q;
   map<int,pair<int,int>> edge;
   for(int i=1;i<=m;i++)
   {
       int a,b;
       cin>>a>>b;
       edge[i]={a,b};
   }
   vector<vector<int>> query;
   query.resize(q+1);
   vector<int> re;
   for(int i=1;i<=q;i++)
   {
       query[i].resize(5);
       int x;
       cin>>x;
       if(x==1)
       {
           // remove this edge;
           int k;
           cin>>k;
           query[i][0]=1;
           query[i][1]=k;
           query[i][2]=edge[k].first;
           query[i][3]=edge[k].second;
           re.push_back(k);
       }
       else
       {
           query[i].push_back(2);
       }
   }

   for(auto x:re)
   {
       edge.erase(x);
   }
   vector<int> pnt;
   vector<int> rank;
   pnt.resize(n+1);
   rank.resize(n+1);
   for(int i=1;i<=n;i++)
   {
       pnt[i]=i;
       rank[i]=1;
   }   
   int ct=n;
   for(auto x:edge)
   {
       int a=x.second.first;
       int b=x.second.second;
       int aroot=findroot(a,pnt);
       int broot=findroot(b,pnt);
       // take union based on rank
       if(aroot!=broot)
       {
           ct--;
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
   vector<int> ans;
   for(int i=q;i>=1;i--)
   {
      
       if(query[i][0]==1)
       {
           // add the edge 
           int a=query[i][2];
           int b=query[i][3];
           int aroot=findroot(a,pnt);
           int broot=findroot(b,pnt);
           // take union based on rank
           if(aroot!=broot)
           {
               ct--;
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
       else 
       {
           // print the component 
           ans.push_back(ct);

       }
   }
   int t=ans.size();
   for(int i=t-1;i>=0;i--)
   {
       cout<<ans[i]<<endl;
   }
}