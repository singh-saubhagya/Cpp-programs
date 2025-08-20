#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
// form 1 
string word1,word2;
int n,m;
int dp[110][110][110];
int ans=0;
int rec(int i,int j, int diff){
    if(i>=n || j>=m)
    {
        return 0;
    }
    if(dp[i][j][diff]!=-1)
    return dp[i][j][diff];
    int temp=0;
    if(diff)
    {
        if(word1[i]==word2[j])
        temp=rec(i+1,j+1,1);
        else 
        temp=1+rec(i+1,j+1,0);
    }
    else{
        if(word1[i]==word2[j])
        temp=1+rec(i+1,j+1,0);
        else 
        temp=0;
    }
    return dp[i][j][diff]=temp;
}
void solve()
{
    cin>>word1>>word2;
    n=word1.length();
    m=word2.length();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int val=rec(i,j,1);
            ans+=val;
        }
    }
    cout<<ans;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}