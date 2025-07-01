#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
vector<int> result;
lli cuberoot(lli n)
{
    lli lo=1,hi=n;
    lli mid;
    lli ans=0;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(mid>=(n/mid)/mid)
        {
            ans=mid;
            hi=mid-1;
        }
        else
        lo=mid+1;

    }
    return ans;
}
void solve()
{
    lli x;
    cin>>x;
    lli a,b;
    for(int i=1;i<=1e4;i++)
    {   a=i;
        b=cuberoot(x-a*a*a);
        if(b!=0 && b*b*b+a*a*a==x)
        {
            result.push_back(1);return;
        }
        
    }
    result.push_back(0);
    return;

}
signed main()
{
  lli q;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>q;
  cout<<endl;

  while(q--)
  {
  solve();
  }
  for(int i:result)
  {
    if(i==1)
    {
        cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;
  }

}