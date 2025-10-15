#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli  n,k;
    cin>>n>>k;
    vector<lli > a,b;
    a.resize(n);
    b.resize(k);
    for(lli  i=0;i<n;i++)
    cin>>a[i];
    for(lli  i=0;i<k;i++)
    cin>>b[i];

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    sort(b.begin(),b.end());
    vector<lli > ps;
    ps.resize(n+2);
    ps[0]=0;
    for(lli  i=1;i<=n;i++)
    {
        ps[i]=ps[i-1]+a[i-1];
    }
    lli  last = 1; 
    lli  ans=0;
    for(auto x:b)
    {

        lli  next=last+x-1;
        // find sum from next to last , 
        lli  sum;
        if(next>n)
        {
            sum=ps[n]-ps[last-1];
        }
        else 
        {
            sum = ps[next-1]-ps[last-1];
        }
       
        
       // cout<<sum<<" "<<x<<" "<<last<<" "<<next<<endl;
        ans+=sum;
        last=next+1;
        if(last>n)
        break;
    }
    if(last<=n)
    {
        ans+=ps[n]-ps[last-1];
    }
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;cin>>t;while(t--)solve();
}