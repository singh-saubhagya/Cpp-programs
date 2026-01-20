#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
  int n;
  int a;
  cin>>n>>a;
  vector<int> arr(n);

  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  if(a<arr[0])
  {
    cout<<a+1<<endl;
  }
  else if (a>arr[n-1])
  {
    cout<<a-1<<endl;
  }
  else 
  {
    auto it1 = upper_bound(arr.begin(),arr.end(),a);
    int sg=arr.end()-it1;
    auto it2 = lower_bound(arr.begin(),arr.end(),a);
    int sl=it2-arr.begin();
    if(sg>sl)
    {
      cout<<a+1<<endl;
    }
    else 
    {
      cout<<a-1<<endl;
    }
  }
  
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}