#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,p;
int dp[100005][7][7];
vector<vector<int>> arr;
int rec(int i,int st,int prev)
{
    if(i==n+1)
    {
        for(auto x:arr[prev])
        {
            if(x==st)
            return 1;
        }return 0;
    }

    if(dp[i][st][prev]!=-1)
    {
        return dp[i][st][prev];
    }
    int ans=0;
    for(auto x:arr[prev])
    {
        ans+=rec(i+1,st,x);
    }
    return dp[i][st][prev]=ans;
}
signed main()
{
    
    cin>>n>>p;
    arr.resize(7);
    arr[1].push_back(2);
    arr[1].push_back(4);
    arr[2].push_back(1);
    arr[2].push_back(3);
    arr[3].push_back(4);
    arr[3].push_back(5);
    arr[4].push_back(1);
    arr[4].push_back(3);
    arr[5].push_back(2);
    arr[5].push_back(5);
    memset(dp,-1,sizeof(dp));
    if(n==1)
    {
        cout<<5<<endl;
        
    }
    else 
    {
        int ans=rec(2,1,1)+rec(2,2,2)+rec(2,3,3)+rec(2,4,4)+rec(2,5,5);
        cout<<ans;
    }

}