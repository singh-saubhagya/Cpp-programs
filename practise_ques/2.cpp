#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli x;
    cin>>x;lli ans;
    vector<lli> arr={9,99,999,9999,99999,999999,9999999,99999999,99999999};
    bool flag=false;
    for(auto y:arr)
    {
        lli val=y*x;
        for(lli i=1;i*i<=val;i++)
        {
            if(val%i==0)
            {
                ans=i-x;
                if(ans>0)
                {
                    flag=true;
                    cout<<i<<" "<<y<<endl;
                    break;
                }
            }
            
        }
        if(flag)
        break;
    }
    cout<<ans<<endl;
    
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}