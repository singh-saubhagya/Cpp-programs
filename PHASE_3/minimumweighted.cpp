#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e18
typedef long long lli;
void dijk(lli  s,vector<vector<pair<lli ,lli >>> g, lli  n, vector<lli > &dist){
    
 vector<bool> marked(n,false);
 priority_queue<pair<lli ,lli >> pq;
 pq.push({0,s});
        while(pq.empty()==false)
        {
            lli  a=pq.top().second;//node
            lli  b=-(pq.top().first);// dist
            pq.pop();
            if(marked[a])
            continue;
            marked[a]=true;
            dist[a]=b;
                for(auto x:g[a])
                {
                    lli  c=x.first;//node
                    lli  d=x.second;// weight;
                    lli  dt=dist[a]+d;
                    if(dt<dist[c])
                    {
                        pq.push({-dt,c});
                    }
                }
        }
}

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<lli  ,lli  >>>g;
        vector<vector<pair<lli  ,lli  >>>gr;
        g.resize(n);
        gr.resize(n);
        for(auto x:edges)
        {
            lli  a=x[0];
            lli  b=x[1];
            lli  c=x[2];
            g[a].push_back({b,c});
            gr[b].push_back({a,c});
        }
       
        vector<lli > dist1(n,inf),dist2(n,inf),dist3(n,inf);
        dijk(src1,g,n,dist1);
        dijk(src2,g,n,dist2);
        dijk(dest,gr,n,dist3);
        lli ans=inf;
        for(int i=0;i<n;i++)
        {
           if(dist1[i]<inf && dist2[i]<inf && dist3[i]<inf)
           ans=min(ans,dist1[i]+dist2[i]+dist3[i]);
        }
        if(ans==inf)
        {
           return -1;
        }
        return ans;
           }
    int main()
    {
        int n,m;
        cin>>n>>m;
        int s1,s2,dt;
        cin>>s1>>s2>>dt;
        vector<vector<int>>edges(m,vector<int>(3));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edges[i][0]=a;
            edges[i][1]=b;
            edges[i][2]=c;
        }
       cout<< minimumWeight( n, edges,  s1,  s2, dt);
        return 0;
    }