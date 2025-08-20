#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
lli  n,m,x,y;
const lli  inf=1e18;
vector<lli > dot;
vector<lli > hsh;
lli  dp[1010][5][1010];
/*
prev 1-. 2-#
*/
lli  rec(lli  i, lli  prev, lli  width)
{
   if(i==(m+1))
    {
       
        if(width<x || width >y)
        return inf;
        return 0;
    }
    if(width>y)
    return inf;

    
    if(dp[i][prev][width]!=-1)
    return dp[i][prev][width];

    lli  ans=inf;
    if(prev==0)// we can add both # or . at the current index 
    {
        lli  val1=hsh[i]-hsh[i-1];
        ans=min(ans,val1+rec(i+1,1,1));
        lli  val2=dot[i]-dot[i-1];
        ans=min(ans,val2+rec(i+1,2,1));
    }
    else if (prev==1)
    {
        lli  val1=hsh[i]-hsh[i-1];
        ans=min(ans,val1+rec(i+1,1,width+1));
        lli  val2=dot[i]-dot[i-1];
        if(width>=x && width<=y)
        ans=min(ans,val2+rec(i+1,2,1));
        
    }
    else if (prev==2)
    {
        lli  val1=dot[i]-dot[i-1];
        ans=min(ans,val1+rec(i+1,2,width+1));
        lli  val2=hsh[i]-hsh[i-1];
        if(width>=x && width<=y)
        ans=min(ans,val2+rec(i+1,1,1));
    }
   
    return dp[i][prev][width]=ans;
}
void solve()
{
    cin>>n>>m>>x>>y;

    vector<vector<char>> g;
    g.resize(n+2);
    for(lli  i=1;i<=n;i++)
    {
       
        g[i].resize(m+2);
        for(lli  j=1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    }
    dot.resize(m+2);
    hsh.resize(m+2);
    hsh[0]=0;
    dot[0]=0;
    for(lli  i=1;i<=m;i++)
    {
        lli  a,b;
        a=0;
        b=0;
        for(lli  j=1;j<=n;j++)
        {
            if(g[j][i]=='#')
            a++;
            else 
            b++;
        }
        dot[i]=b;
        hsh[i]=a;
    }
    for(lli  i=1;i<=m;i++)
    {
        dot[i]=dot[i-1]+dot[i];
        hsh[i]=hsh[i-1]+hsh[i];
      
    }
    memset(dp,-1,sizeof(dp));
   
    cout<<rec(1,0,0);
}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}