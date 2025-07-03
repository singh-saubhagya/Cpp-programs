#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
void solve()
{
    string str;
    cin>>str;
    lli  pt=0;
    lli  n=str.length();
    lli  ct=0;
    lli  ans=0;
    for(lli  i=0;i<(2*n-1);i++)
    {   
        if(str[i%n]=='1')
        {
            ct++;
            ans=max(ct,ans);
        }
        else
        {
            ct=0;

        }
    } 
    lli  val=0;  
    for(lli  i=0;i<=n;i++)
    {
        if(ans-i>0)
        {
            val=max(val,(ans-i)*(i+1));
        }
        else 
        break;
    }
    cout<<val<<endl;
}
signed main()
{
    lli  t;cin>>t;while(t--)solve();
}


