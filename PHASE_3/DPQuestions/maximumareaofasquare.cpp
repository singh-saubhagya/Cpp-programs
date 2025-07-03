#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define inf 1e9
int n,m;
vector<vector<int>> arr;
vector<vector<int>> dp;
int sol=0;
int rec(int i,int j)
{
   
    if(i<0 || j<0 || i>=n || j>=m )
    {
        return 0;
    }

    if(i==0 && j==0)
    {
        sol=max(sol,arr[0][0]);
        return dp[0][0]=arr[0][0];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0;
    if(arr[i][j]==0)
    {
        ans=0;
    }
    else
    {
        ans=1+min(min(rec(i-1,j),rec(i,j-1)),rec(i-1,j-1));
    }
    sol=max(sol,ans);
    return dp[i][j]=ans;

}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        arr=vector<vector<int>>(n+1,vector<int>(m+1));
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j])
                {
                    rec(i,j);
                }
            }
        }
        
        cout<<sol*sol<<endl;
        sol=0;
    }
}