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
    arr.resize(n);
    int a[105];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(auto x:arr)
    {
        a[x]++;
        if(a[x]==2)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return ;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  
}