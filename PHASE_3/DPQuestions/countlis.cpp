#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;  
#define m 1000000007
vector<int> arr;
int dp[1002];
int rec(int i)
{
    if(i<0)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ans=1;
    for(int x=i-1;x>=0;x--)
    {
        if(arr[x]<arr[i])
        {
            ans=max(ans,1+rec(x));
        }
    }
    return dp[i]=ans;
}
int ct[1004];
int countways(int i,int ans)
{
    if(i==0 || ans==1)
    {
        return 1;
    }
    
    if(ct[i]!=-1)
    return ct[i];

    int ways=0;
    for(int x=i-1;x>=0;x--)
    {
        if(arr[x]<arr[i] && dp[x]==ans-1)
        {
            ct[x]=countways(x,ans-1);
            ways=ways%m+ct[x]%m;
            ways=ways%m;
        }
    }
    return ct[i]=ways;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    arr.resize(n+1);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp)); 
    for(int i=n-1;i>=0;i--)
    {
        rec(i);
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }

    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==ans)
        {
            
            temp.push_back(i);
        }
    }
    memset(ct,-1,sizeof(ct));
    int sol=0;
    for(auto x:temp)
    {
   
        sol=(sol%m+countways(x,ans)%m)%m;
    }
    cout<<sol<<endl;
    }
    
} 