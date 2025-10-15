#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
  int n;
  cin>>n;
  vector<int> arr;
  arr.resize(n+2);
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
  vector<int> idx;
  idx.resize(n+2);
  for(int i=1;i<=n;i++)
  {
    idx[arr[i]]=i;
  }
  bool flag=false;
  for(int i=1;i<=n;i++)
  {
    int a=n+2;
    int b=0;
    for(int j=n;j>=n+1-i;j--)
    {
      //cout<<j<<idx[j]<<endl;
      a=min(a,idx[j]);
      b=max(b,idx[j]);
     
    }
     if(b-a!=(i-1))
      {
        flag=true;
       // cout<<i<<" "<<a<<" "<<b<<endl;
        break;
      }
  
  }
  if(flag)
  cout<<"NO"<<endl;
  else 
  cout<<"YES"<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;cin>>t;while(t--)solve();
}