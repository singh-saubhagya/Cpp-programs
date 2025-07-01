#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long
const lli m=1e9+7;
vector<lli> arr;
vector<lli> presum;
vector<lli> result;
void input(lli n)
{
    lli sum=0;
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;       
        arr.push_back(x);
        sum=(sum+x)%m;
        sum=(sum+m)%m;
        presum.push_back(sum);
       
    }
}

void solve()
 {
   lli l, r;
    cin >> l >> r;
    l--; // Convert to 0-based index
    r--; // Convert to 0-based index

    lli range_sum;
    if (l > 0) {
        range_sum = (presum[r] - presum[l - 1] + m) % m;
    } else {
        range_sum = presum[r];
    }

    result.push_back(range_sum);
 }

 signed main()
 {
   lli q,n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
  cin>>n>>q;
  input(n);
  while(q--)
  {
   solve();
  }
  cout<<endl;
   for(lli i:result)
   {
    cout<<(i%m+m)%m<<endl;
   } 
 }