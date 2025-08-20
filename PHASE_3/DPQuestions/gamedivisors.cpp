/*
In this question we have to take divisors of current no n , and let change the state to n-d, d is divisor,  then n-d is state for other player
the player loses if he can't choose any divisor , and chossing 1 and n , for state n , is prohibited.
time complexity is xlog(x), x is starting state.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<vector<int>> divsr;
int dp[100000];
bool rec(int n)
{
    if(dp[n]!=-1)
    return dp[n];
    bool flag=true;
    for(auto x:divsr[n])
    {
        if(x!=1 && x!=n)
        {
            flag=rec(n-x);
            if(flag==false)
            {
                break;
            }
        }
    }
    // flag=false implies current state wiin 
    return dp[n]=!flag;
}
int magic(int x)
{
    if(x&1)// odd losing 
    return 0;
    
    if((x&(x-1))==0)// power of 2 
    {
        int ct=0;
        int n=x;
        while(n!=1)
        {
            ct++;
            n/=2;
        }
        if(ct&1)
        return 0;
        return 1;
    }
    return 1;

}
void solve(int x)
{   
    
    
    divsr.resize(x+3);
    for(int i=1;i<=x;i++)// xlog(x) how ? explained below 
    {
        for(int j=i;j<=x;j+=i)
        {
            divsr[j].push_back(i);
        }
    }
    memset(dp,-1,sizeof(dp));
    //if((x&1)==0 && magic(x)==0)// this condn tell us that only on odd powers of 2  and odd x leading us to losing state;
    cout<<x<<": "<<rec(x)<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    // int x;
    // cin>>x; 
    solve(t);
}
 
}

// 1 will be in 1,2,3,....x;
// 2 will be in 2,4,6,8...x;
// total no of divisorw will be x/1 + x/2 + x/3 + .... x/x = x*logx