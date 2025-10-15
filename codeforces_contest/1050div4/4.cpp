#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli n;
    cin>>n;
    vector<lli> a,b;
    for(int i=0;i<n;i++)
    {
        lli temp;
        cin>>temp;
        if(temp&1)
        a.push_back(temp);
        else 
        b.push_back(temp);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int nn=a.size();
    lli ans=0;
    if(nn>=1)
    {
    lli cal=nn-1;
    cal=cal/2;
    cal++;
    
 
    for(int i=0;i<cal;i++)
    ans+=a[i];
    for(auto x:b)
    ans+=x;
    
    }
    
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}