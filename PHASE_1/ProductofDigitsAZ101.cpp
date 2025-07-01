#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
const lli k=1e9+7;
void solve()
{
    lli n;
    cin>>n;
    lli result=1;
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        x=x%k;
        if(x==0)
        {
            
            result=0;
        }
        else
        {
            result=result*x;
            result=result%k;
        }


    }
    
    cout<<result<<endl;
}
signed main()
{

  lli t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>t;

  while(t--)
  {
  solve();
  }

}