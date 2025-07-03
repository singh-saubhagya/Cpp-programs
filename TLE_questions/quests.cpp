#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;
void solve(){
    lli n,k;
    cin>>n>>k;
    vector<lli> a,b;
    a.resize(n+2);b.resize(n+2);
    for(lli i=1;i<=n;i++)
    cin>>a[i];
    for(lli i=1;i<=n;i++)
    cin>>b[i];
   
    vector<lli> ps;
    ps.resize(n+2);
    ps[0]=0;
    vector<lli> ma;
    ma.resize(n+2);
    ma[0]=-1e18;
    for(int i=1;i<=n;i++)
    {
        ps[i]=ps[i-1]+a[i];
        ma[i]=max(b[i],ma[i-1]);
    }
    lli ans=a[1];
    for(int i=1;i<=n;i++)
    {
        lli rem=k-i;
        if(rem>=0)
        ans=max(ans,ps[i]+ma[i]*rem);
        else 
        break;
    }
    cout<<ans<<endl;
}
signed main()
{
    lli t;
    cin>>t;
    while(t--)
    solve();
}