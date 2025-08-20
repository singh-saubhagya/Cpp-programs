#include<bits/stdc++.h>
using namespace std;
#define inf 1e18
typedef long long lli;
    vector<vector<pair<lli ,lli >>> g;
    lli  n;

    vector<lli> dp;
    lli kk;
    void rec(lli  i,lli pl,lli mpv)
    {
        if(pl>kk)
        return ;

        if(dp[i]==-1)
        {
            dp[i]=mpv;
        }
        else 
        {
            dp[i]=max(mpv,dp[i]);
        }
        if(i==n-1)
        {
            return;
        }
        

        for(auto x:g[i])
        {

            lli  node =x.first;
            lli wt=x.second;
            rec(node,pl+wt,min(wt,mpv));

        }

        
        return ;
    }
  int  findMaxPathScore(vector<vector<lli >>& edges, vector<bool>& online, long long k) {
            n=online.size();
            kk=k;
            g.resize(n+1);
          
            for(auto x:edges)
            {
                lli  a=x[0];
                lli  b=x[1];
                lli wt=x[2];
                if(online[a] && online[b])
                {
                    g[a].push_back({b,wt});
                   
                }

            }
            dp.assign(n+2,-1);
            rec(0,0,inf);
            
            return dp[n-1];
    }


    signed main()
    {
        vector<vector<lli >> edges = {
        {0, 1, 5},
        {1, 3, 10},
        {0, 2, 3},
        {2, 3, 4}
    };

    vector<bool> online = {true, true, true, true};

    lli  k = 10;
    cout<<findMaxPathScore(edges,online,k);
    }