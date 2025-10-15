#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    int x,n;
    cin>>x>>n;
    if(n&1)
    {
        cout<<x<<endl;
    }
    else 
    cout<<0<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}