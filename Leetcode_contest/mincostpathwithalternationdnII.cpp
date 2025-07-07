  #include<bits/stdc++.h>
  using namespace std;
  
  typedef long long lli;
    lli nn;
    lli mm;
    vector<vector<int>>wc;
    vector<vector<lli>>dp;
    #define inf 1e18
    lli rec(lli i, lli j)
    {
        if(i==nn-1 && j==mm-1)
        {
            return nn*mm;
        }
        if(i>=nn || j>=mm)
        return inf;

        if(dp[i][j]!=-1)
            return dp[i][j];

        lli ans=inf;
        lli ec=(i+1)*(j+1);
        lli wt=wc[i][j];
        
        ans=min(ans,rec(i+1,j)+wt+ec);
        ans=min(ans,rec(i,j+1)+wt+ec);
    
        return dp[i][j]=ans;
    }
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        dp=vector<vector<lli>>(n+1,vector<lli>(m+1,-1));
        nn=n;
        mm=m;
        waitCost[0][0]=0;
        waitCost[n-1][m-1]=0;
        wc=waitCost;
        return rec(0,0);
    }

    signed main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> waitcost;
        waitcost.resize(n+1);

        for(int i=0;i<n;i++)
        {
            waitcost[i].resize(m+1);
            for(int j=0;j<m;j++)
            {
                cin>>waitcost[i][j];
            }
        }
       cout<<minCost(n,m,waitcost);

    }