#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, int node , set<int> &arr, vector<int>&vis,int color)
    {
        vis[node]=color;
        arr.insert(node);
        for(auto x:g[node])
        {
            if(vis[x]==-1)
            {
                    dfs(g,x,arr,vis,color);
            }
        }

    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<vector<int>> g;
        g.resize(c+2);
        for(auto x:connections)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<set<int>> cmp;// componet
        vector<int> vis;
        vis.assign(c+2,-1);
        int k=0;
        for(int i=1;i<=c;i++)
        {
            if(vis[i]==-1)
            {

                set<int> arr;
                dfs(g,i,arr,vis,k);
                k++;
                cmp.push_back(arr);
            }
        }
        vector<int> ans;
        for(auto x:queries)
        {
            int a=x[0];
            int b=x[1];
            if(a==1)
            {
                int pn=vis[b];
                auto it=cmp[pn].find(b);
                if(it!=cmp[pn].end())
                {
                    ans.push_back(b);
                }
                else 
                {
                    if(cmp[pn].size()>0)
                    {
                        auto temp=cmp[pn].begin();
                        int val=*temp;
                        ans.push_back(val);
                    }
                    else 
                    ans.push_back(-1);
                }
            }
            else 
            {
                int pn=vis[b];
                if((cmp[pn].find(b))!=(cmp[pn].end()))
                cmp[pn].erase(b);
            }
        }
        return ans;
    }
    signed main()
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<vector<int>> edges,queries;
        edges.resize(m);queries.resize(q);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[i].push_back(a);
            edges[i].push_back(b);
        }
        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[i].push_back(a);
            edges[i].push_back(b);
        }
        
        processQueries(n,edges,queries);

    }