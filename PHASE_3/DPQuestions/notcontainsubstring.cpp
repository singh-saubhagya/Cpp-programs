/*
This is a form 1 problem , where we have to find all the strings of length n , such that it doesn't contain substring , 0100 , 
so what are we going to do is maintain the last theree digits at each level , excluding the digit at current level , i.e. if we are at level l, 
we have digits at level l-1, l-2,l-3, . We are storing the last three bits using bitmasking.

The case where the string will contain 0100 , will be if prev is 2 (010) and current bit placed at level is 0, then invalid solution. 
So as soon as we get 2 as prev bit we only place 1 ,there resulting in 0101, 

There is a special case when prev is 2 ,  and placing 0 at current level is valid, it is when we have no of bits as 2 for representin 2 . i.e 10 as 2, and appending it with 0 , will be 4 as 100 as substring and not 0100 .


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define enld '\n'
int n;
int dp[100003][10];
int rec(int level, int x)
{
       
    if(level==n)
    {
        return 1;
    }
    if(dp[level][x]!=-1)
    return dp[level][x];

    
    if(x==2 && level>=3)
    {
        return dp[level][x]=rec(level+1,5);
    }
    int a=(x<<1 | 1)&7;
    int b=(x<<1)&7;
    int ans=0;
    ans=rec(level+1,a)+rec(level+1,b);
    return dp[level][x]=ans; 
    
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