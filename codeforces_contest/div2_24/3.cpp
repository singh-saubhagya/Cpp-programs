#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
void solve()
{
    lli  n;
    cin>>n;
    vector<lli >arr;
    arr.resize(n);
    for(lli  i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    lli  ans=0;
    
    for(lli  i=n-1;i>=0;i--)
    {
        lli  st=i;
        lli  en=i-1;
        if(en!=-1)
        {
        ans+=max(arr[st],arr[en]);
        lli  val=min(arr[st],arr[en]);
        arr[st]-=val;
        arr[en]-=val;
        
        i=en;
        }
        else 
        {
           ans+=arr[i];
        }
    
    }
    cout<<ans<<endl;
}
signed main()
{
  cin.tie(0); cout.tie(0);
  lli  t;
  cin>>t;
  while(t--)
  solve();
}