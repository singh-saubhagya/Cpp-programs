#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define int long long
void solve()
{
    int n;
    cin>>n;
    int a=10;
    int result=log(n)/log(a);
    result=n*result;
    result=log(result)/log(a);
    result=n*result;
    cout<<result;
    
}
signed main()
{
  int q;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  cout<<endl;
  q=1;
  while(q--)
  {
  solve();
  }

}