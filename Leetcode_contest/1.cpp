#include<bits/stdc++.h>
using namespace std;
#define inf 1e18
typedef long long lli;
    vector<vector<pair<int,int>>> g;
    int n;
    bool check(lli mid, lli k)
    {
        vector<bool> marked;
        marked.assign(n+1,false);
        vector<lli> dist;
        dist.resize(n+1);
        for(int i=0;i<n;i++)
        dist[i]=inf;

        priority_queue<pair<lli,lli>> pq;
        pq.push({0,0});
        dist[0]=0;
        while(pq.empty()==false)
        {
            pair<lli,lli> val=pq.top();
            pq.pop();
            lli node=val.second;
            lli dt=-val.first;
            while(marked[node])
            continue;
            marked[node]==true;

            for(auto x:g[node])
            {
                pair<lli,lli> temp=x;
                int a=temp.first;
                int wt=temp.second;
                if(dt+wt>k)// threshold cross
                continue;
                if(wt>=mid)// checking if min edges is greater than mid 
                {
                    int fd=dt+wt;
                    if(fd<dist[a])
                    {
                        pq.push({-fd,a});
                        dist[a]=fd;
                    }
                }
                
            }
        }
        if(dist[n-1]==inf)
        return false;
        return true;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            n=online.size();
            
            g.resize(n+1);
            lli  low=inf;
            lli  high=-inf;
            for(auto x:edges)
            {
                int a=x[0];
                int b=x[1];
                lli wt=x[2];
                if(online[a] && online[b])
                {
                    g[a].push_back({b,wt});
                    low=min(low,wt);
                    high=max(high,wt);
                }

            }
            lli ans=0;
            while(low<=high)
            {
                lli mid=low+(high-low)/2;
                // cout<<mid<<endl;
                if(check(mid,k))
                {
                    ans=mid;
                    low=mid+1;
                }
                else 
                {
                    high=mid-1;
                }
            }

        return ans;
    }


    signed main()
    {
        vector<vector<int>> edges = {
        {0, 1, 7},
        {1, 4, 5},
        {0, 2, 6},
        {2, 3, 6},
        {3, 4, 2},
        {2, 4, 6}
    };

    // Online status of each node (node 3 is offline)
    vector<bool> online = {true, true, true, false, true};

    // Max cost constraint
    int k = 12;
    cout<<findMaxPathScore(edges,online,k);
    }