#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
lli findgcd(lli a,lli b)
{
    if(a==0)
    return b;
    return findgcd(b%a,a);
}
void solve(){
    lli n;
    cin>>n;
    vector<lli> arr(n+1);
    for(lli i=1;i<=n;i++)
    cin>>arr[i];
    lli ans=abs(arr[n]-arr[1]);
    for(lli i=2;i<=(n/2);i++)
    {
        lli a=i;
        lli b=n-(i-1);
        ans=findgcd(ans,abs(arr[b]-arr[a]));
    }
    cout<<ans<<endl;
}
signed main()
{
    int t;cin>>t;while(t--)solve();
}