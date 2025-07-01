#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
vector<lli> id;
vector<vector<lli>> g;
vector<lli> topo;
int main()
{
    lli n,m;
    cin>>n>>m;
    g.resize(n+1);
    id.resize(n+1,0);
    for(lli i=0;i<m;i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        id[b]++;
    }
    priority_queue<lli> pq;

    for(lli i=1;i<=n;i++)
    {
        if(id[i]==0)
        {
            pq.push(-i);
        }
    }
    while(pq.empty()==false)
    {
        lli x=-pq.top();
        pq.pop();
        topo.push_back(x);
        for(auto z:g[x])
        {
            id[z]--;
            if(id[z]==0)
            {
                pq.push(-z);
            }
        }
    }
    if(topo.size()<n)
    cout<<-1<<endl;
    else
    {
         for(auto x:topo)
         {
           cout<<x<<" ";
         }
    }   
    }
  