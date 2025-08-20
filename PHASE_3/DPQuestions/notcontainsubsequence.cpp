/*
This is also a form 1 problem ;
here state is level and no of char matching with the sub seq, at each level , we can place 2 bits . such that 1 bit matches with the subseq and the other not matches with currect subseq, 
if matches then we increase the match count and if match count reaches the subseq size then its a invalid solution , return 0.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
int n;
int dp[100002][10];
int rec(int level ,int match)
{
    if(match==4)
    return 0;
    if(level==n)
    {
        if(match == 4)
        return 0;
        return 1;
    }
    if(dp[level][match]!=-1)
    return dp[level][match];

    int ans=0;
    ans=rec(level+1,match+1)+rec(level+1,match);
    return dp[level][match]=ans; 
    
}
void solve()
{
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
}
signed main()
{
    solve();
}