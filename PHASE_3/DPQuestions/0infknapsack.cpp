// earlier , what we were doing is either select the ith element and move to next i+1 , or don't select the ith and move the i+1 , element.
// in 0-∞ knapsack we will select the ith element and will not move to next element rather than remain in that state only. 
#include<bits/stdc++.h>
using namespace std;
int n,w;
vector<pair<int,int>> arr;
int dp[3000][3000];
int rec(int i,int j)
{
    if(j==0)
    return 0;
    if(i==n)
    return 0;

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=rec(i+1,j);
    if(j>=arr[i].first)
    {
        ans=max(ans,rec(i,j-arr[i].first)+arr[i].second);
    }
    return dp[i][j]=ans;

    /*
    this one is not optimzed version of 0 to inf knapsack 
    T.C.: nw^2
    int ans=0;
    for(int x=0;x<=j/arr[i].first;x++)
    {
        ans=max(ans,rec(i+1,j-x*arr[i].first)+x*arr[i].second);
    }
    return dp[i][j]=ans;
    
    */

}
signed main(){
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,w);
    cout<<ans<<endl;
}