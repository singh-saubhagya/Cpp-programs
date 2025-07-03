#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lli;



void solve()
{
    lli  n,k,q;
    cin>>n>>k>>q;
    vector<lli >arr(n);
    for(lli  i=0;i<n;i++)
    cin>>arr[i];

    lli  head=-1;
    lli  tail=0;
    lli  ans=0;
    while(tail!=n)
    {
        while(head+1<n && arr[head+1]<=q)
        {
            head++;
        }
        lli  no=head-tail+1;
        if(no>=k)
        {
            ans+=no-k+1;
        }
        if(tail-head>=1)
        {
            tail++;
            head=tail-1;
        }
        else
        {
            tail++;
        }
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