#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
string word1,word2;
int n,m;


/*
diff =0 , no of substring with no diff; 
diff =1 , no of substring with 1 diff;
In this question at the state is 
dp[i][j][diff]: the no substring starting with i,j , which has 1 character different
or in most cases no of substring from i,j, is equal to lenght of longest substring start at i ,j ;

*/
int dp[1010][1010][3];
int rec(int i,int j, int diff)
{
    if(i==n || j==m )
    return 0;

    if(dp[i][j][diff]!=-1)
    return dp[i][j][diff];

    int ans=0;
    if(diff)
    {
        if(word1[i]==word2[j])
        {
          ans=rec(i+1,j+1,1);
        }
        else 
        {
          ans=1+rec(i+1,j+1,0);
        }
    }
    else 
    {
        if(word1[i]==word2[j])
        {
            ans=1+rec(i+1,j+1,0);
        }
        else 
        ans=0;
    }
    return dp[i][j][diff]=ans;
}
void solve()
{
    cin>>word1>>word2;
    n=word1.length();
    m=word2.length();
    memset(dp,-1,sizeof(dp));
    int ans=0;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
            ans+=rec(i,j,1);
    }
   }
   cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}