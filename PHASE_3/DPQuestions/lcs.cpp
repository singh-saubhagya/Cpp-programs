#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
string a,b,c;
int n,m,o;
int dp[102][102][102];
int rec(int i, int j, int k)
{
        if(i>=n || j>=m || k>=o)
        {
            return 0;
        }
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }

        int ans=0;
        ans=max(ans,rec(i+1,j,k));
        ans=max(ans,rec(i,j+1,k));
        ans=max(ans,rec(i,j,k+1));
        if(a[i]==b[j] && b[j]==c[k])
        {
            ans=max(ans,1+rec(i+1,j+1,k+1));
        }
        return dp[i][j][k]=ans;
        

}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        n=a.length();
        m=b.length();
        o=c.length();
        if(n==0 || m==0 || o==0)
        {
            cout<<0<<endl;continue;
        }
        memset(dp,-1,sizeof(dp));
        int ans= rec(0,0,0);
        if(ans>0)
        cout<<ans<<endl;
        else 
        cout<<0<<endl;
    }
   

}