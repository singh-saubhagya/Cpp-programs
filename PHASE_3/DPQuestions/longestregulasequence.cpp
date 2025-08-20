#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
string str;
int n;
vector<int>bnl;
int dp[1000010];
void findbalance()
{
    stack<int> s;
    bnl.resize(n+2);
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        if(ch=='(')
        {
            s.push(i);
        }
        else 
        {
            if(s.empty())
            {
                bnl[i]=-1;
            }
            else 
            {
                int x=s.top();
                bnl[i]=x;
                s.pop();
            }
        }
    }
}
int rec(int i)
{
    if(i<=0)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    int ans=0;
    if(str[i]==')')
    {
        int idx=bnl[i];
        if(idx==-1)
        ans=0;
        else 
        {
            ans=i-idx+1+rec(idx-1);
        }
    }
    return dp[i]=ans;
}
void solve()
{
    cin>>str;
    n=str.length();
    findbalance();
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int val=rec(i);
        ans=max(ans,val);
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(rec(i)==ans)
        ct++;
    }
    if(ans==0)
    cout<<0<<" "<<1<<endl;
    else 
    cout<<ans<<" "<<ct<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}