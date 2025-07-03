// state -> dp[i][j]: min amount of initial heal req to go grom i,j to n-1,m-1
// transition -> 


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
#define inf 1e9
lli n,m;
vector<vector<lli >> arr,dp;
lli  rec(lli  i,lli  j)
{
    // cout<<i<<" "<<j<<endl;
    if(i==n-1 && j==m-1)// base case 
    {
        lli  ans;
        if(arr[n-1][m-1]<=0)
        {
            ans= 1-arr[n-1][m-1];
        }
        else 
        ans=1;
        return dp[n-1][m-1]=ans;
    }

    if(i>=n || j>=m)
    return inf;

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    lli  sol=1;
    // cout<<i<<" "<<j<<"->"<<i+1<<" "<<j<<endl;
    lli  ans=rec(i+1,j);
    // cout<<i<<" "<<j<<"->"<<i<<" "<<j+1<<endl;
    ans=min(ans,rec(i,j+1));
    lli  req=ans;
    if(req<=arr[i][j])
    {
        sol=1;
    }
    else 
    {
       lli  diff=req-arr[i][j];
       sol=diff;
    }
    return dp[i][j]=sol;
    // dp[i][j] = max(1LL, min(rec(i+1,j), rec(i,j+1)) - arr[i][j]);
    // return dp[i][j];
}
signed main(){
    lli t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        arr=vector<vector<lli >>(n+2,vector<lli >(m+2));
        dp=vector<vector<lli >>(n+2,vector<lli >(m+2,-1));
        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<m;j++)
            {
                cin>>arr[i][j];
                
            }
          
        }
        cout<<rec(0,0)<<endl;
        // for(lli  i=0;i<n;i++)
        // {
        //     for(lli  j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
}