#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
lli  findgcd(lli  a,lli  b)
{
    if(b%a==0)
    return a;

    return findgcd(b%a,a);
}
void solve(){
    lli  n;
    cin>>n;
    vector<lli > arr(n+1);
    vector<lli > ps;
    ps.resize(n+1);
    ps[0]=0;
    for(lli  i=1;i<=n;i++)
    {
    cin>>arr[i];
    if(i!=1)
    {
        ps[i]=ps[i-1]+arr[i];
    }      
    else 
    ps[i]=arr[i];
    }
    lli  ans=1;
    for(lli  i=1;i<=n-1;i++)
    {
        ans=max(ans,findgcd(ps[i],ps[n]-ps[i]));
    }
    cout<<ans<<endl;
}
signed main()
{
    lli  t;
    cin>>t;
    while(t--)
    solve();
}