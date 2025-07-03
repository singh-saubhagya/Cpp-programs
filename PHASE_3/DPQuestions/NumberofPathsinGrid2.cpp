/*
in this question we are counting no of paths from 0,0 to n-1,m-1, after breaking atmost k walls.alignas

but if we are asked to break exactly k walls, then we will change the base case only , and use == in place of >=.

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define mm 1000000007
#define endl '\n'
lli n,m,k;
vector<vector<vector<lli>>> dp;
vector<vector<lli>> arr;
lli rec(lli i,lli j, lli w)
{
  
    if(i<0 || j<0 || i>=n || j>=m || w<0)
    return 0;

    if(i==0 && j==0)
    {
        if(arr[0][0]==1)
        {
            if(w>0)
            {
                w--;
            }
            else
            {
                return 0;
            }
        }
        if(w>=0)
        return 1;
        else return 0;
    }
    if(arr[i][j]==1)
    {
        if(w==0)
        {
            return 0;
        }
    }

    if(dp[i][j][w]!=-1)
    {
        return dp[i][j][w];
    }
    lli ans=0;
    if(arr[i][j]==1)
    {
        lli a=rec(i-1,j,w-1);
        lli b=rec(i,j-1,w-1);
        ans=a%mm+b%mm;
        ans=ans%mm;
    }
    else 
    {
        lli a=rec(i-1,j,w);
        lli b=rec(i,j-1,w);
        ans=a%mm+b%mm;
        ans=ans%mm;
    }
    return dp[i][j][w]=ans;

}
signed main()
{
    lli t;
    cin>>t;
   
    
    while(t--)
    {
        
     
        cin>>n>>m>>k;
        arr = vector<vector<lli>>(n, vector<lli>(m));
        for(lli i = 0; i < n; i++) 
        {
        for(lli j = 0; j < m; j++) 
        {
        cin >> arr[i][j];
        }
        }
        
        dp=vector<vector<vector<lli>>>(n+1,vector<vector<lli>>(m+1,vector<lli>(k+1,-1)));
        lli ans=0;
            ans=ans%mm+rec(n-1,m-1,k)%mm;
            ans=ans%mm;
            cout<<ans<<endl;
        
    }
}