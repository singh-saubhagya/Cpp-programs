#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

// // logic behind this code 
// (x*10^d + y) %(x+y)==0, then for some d, lets say d=3 , 1000x+y, 999x+ x+y, we can rewrite the eqn as 
// 999x%(x+y)==0 + (x+y)%x+y, now we are left with this , 999x%(x+y)==0 only, so we will just calculta the divisor of x and subtract y from it , 
// d is no digits of y . 
void solve()
{
  lli x;
  cin>>x;
  vector<lli> arr={0,9,99,999,9999,99999,999999,9999999,99999999,9999999999};
  int n=arr.size();
  lli pw=1;
  lli ans;
  bool flag=false;
  for(int i=1;i<n;i++)// i is here no of digit.
  {
    lli val=arr[i]*x;
    lli low=pw;
    lli high=pw*10-1;
    for(int j=low;j<=min(high,val);j++)
    {
      if(val%j==0)
      {
        ans=j-x;
        if(ans>0)
        {
          flag=true;
          //cout<<arr[i]<<" "<<i<<" "<<low<<" "<<high<<" "<<j<<endl;
          break;
        }
      }
      if(flag)break;
    }
    pw=pw*10;
    }
    cout<<ans<<endl;
} 
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--) solve();
}