#include<bits/stdc++.h>
using namespace std;
 typedef long long lli;
    lli nn;
    lli mm;
    vector<vector<int>>wc;
    vector<vector<vector<lli>>>dp;
    #define inf 1e18
    lli rec(lli i, lli j, lli flag)
    {
        if(i==nn-1 && j==mm-1)
        {
            return nn*mm;
        }
        if(i>=nn || j>=mm)
        return inf;

        if(dp[i][j][flag]!=-1)
            return dp[i][j][flag];

        lli ans=inf;
        lli ec=(i+1)*(j+1);
        lli wt=wc[i][j];
        if(flag==1)
        {
            ans=min(ans,rec(i+1,j,0)+ec);
            ans=min(ans,rec(i,j+1,0)+ec);
        }
        else 
        {
             ans=min(ans,rec(i,j,1)+wt);
             ans=min(ans,rec(i,j,1)+wt);
        }   
        return dp[i][j][flag]=ans;
    }
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        dp=vector<vector<vector<lli>>>(n+1,vector<vector<lli>>(m+1,vector<lli>(3,-1)));
        nn=n;
        mm=m;
        wc=waitCost;
        cout<<rec(0,0,1);
    }
    signed main()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> waitCost;
        waitCost.resize(n);
        for(int i=0;i<n;i++)
        {waitCost[i].resize(m);
            for(int j=0;j<m;j++)
            {
                cin>>waitCost[i][j];
            }
        }
        minCost(n,m,waitCost);
        
       
    }


