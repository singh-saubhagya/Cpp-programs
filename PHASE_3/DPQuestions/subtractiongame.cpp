#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
int dp[3][1000002];
int n;
int rec(int turn , int left)
{
    if(left==0)
    return 0;

    if(dp[turn][left]!=-1)
    return dp[turn][left];
    int ans=0;
    for(int m=0;(1<<m)<=left;m++)
    {
        int nt=(turn+1)%2;
        if(rec(nt,left-(1<<m))==0)
        {
            ans=1;
            break;
        }
    }
    return dp[turn][left]=ans;
}
signed main()
{
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));// we can move this out as n is independent of the recurison funciton.
    while(t--)
    {
        cin>>n;
        
        int ans=rec(1,n);// 1:vived 2:abhishek
        if(ans)
        cout<<"Vivek"<<endl;
        else 
        cout<<"Abhishek"<<endl;
    }
}