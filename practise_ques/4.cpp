#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

void solve()
{
    int k, x;
    cin>>k>>x;
    
    for(int i=1;i<=k;i++)
    {
        x=x*2;
    }
    cout<<x<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}